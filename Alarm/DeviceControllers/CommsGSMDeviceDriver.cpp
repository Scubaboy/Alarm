#include "CommsGSMDeviceDriver.h"
#include <wiringPi.h>
#include <unistd.h>
#include <sstream>
#include "ReceivedMessage.h"

CommsGSMDeviceDriver::CommsGSMDeviceDriver(ILogger* logger, 
                                           IPortController* portController, 
                                           IGPIOController* gpioController, 
                                           IStringResponseParser* stringParser,
                                           IATCommandSequenceController* atCommandController)
{
   this->logger = logger;
   this->portController = portController;
   this->gpioController = gpioController;
   this->stringParser = stringParser;
   this->atCommandController = atCommandController;
   this->isInitialised = false;
}

void CommsGSMDeviceDriver::Initialise()
{
    string testResponse;
    
    //Configure UART
    this->portController->OpenPort("/dev/ttyAMA0",9600);
    
    //Setup Power gpio pins
    this->gpioController->pullUpDnControlGPIOl(0,PUD_DOWN);
    this->gpioController->pullUpDnControlGPIOl(1,PUD_DOWN);
    
    //Power cycle GSM module
    this->gpioController->DigitalWrite(0, HIGH);
    delay(1200);
	this->gpioController->DigitalWrite(0, LOW);
	delay(5000);
    
    //Send test command.
    this->portController->SendData("AT");
    sleep(2);
    
    testResponse = this->portController->ReadData();
    
    if (this->stringParser->HasString(testResponse,"OK"))
    {
        //Disable command reply echo
        this->portController->SendData("ATE 0");
        sleep(1);
        testResponse = this->portController->ReadData();
        if (this->stringParser->HasString(testResponse,"OK"))
        {
            this->logger->LogInfo("GSM module ready command echo disabled!");
            this->isInitialised = true;
        }
        else
        {
            this->logger->LogInfo("GSM module ready command echo disable failed!");
        }
    }
    
}

ReceivedMessage CommsGSMDeviceDriver::GetNextMsg() 
{
    ReceivedMessage msg;
    
    if (this->isInitialised)
    {
        auto commandList = this->atCommandController->ReadSMSCommandSequence();
        std::vector<ATCommand>::iterator iter = commandList.begin();
        auto fialedResponse = false;
        string testResponse;
        
        
        while (iter != commandList.end() && !fialedResponse)
        {
            auto command = *iter;
            
            this->portController->SendData(command.Command.c_str());
            testResponse = this->portController->ReadData(true);
          
            
            if (command.ExpectedResponse == "")
            {
                msg = this->stringParser->BuildMessage(testResponse);
            }
            else
            {
                if (!this->stringParser->HasString(testResponse,command.ExpectedResponse))
                {    
                    fialedResponse = true;
                }
            }   
         
            iter++;   
        }
    }
    
    return msg;
}

bool CommsGSMDeviceDriver::SendMsg(string msg, string number)
{
    if (this->isInitialised)
    {
        string testResponse;
        
        this->portController->SendData("AT+CMGF=1");
        testResponse = this->portController->ReadData(true);
        if (this->stringParser->HasString(testResponse,"OK"))
        {
            std::stringstream msgToWrite;
            
            msgToWrite << "AT+CMGS=" << "\"" << number << "\"";
            
            this->portController->SendData(msgToWrite.str().c_str());
            //sleep(1);
            testResponse = this->portController->ReadData(true);
            if (this->stringParser->HasString(testResponse,">"))
            {
                msgToWrite.clear();
                msgToWrite.str(std::string());
                msgToWrite << msg;
                this->portController->SendData(msgToWrite.str().c_str(),"\x1a");
                testResponse = this->portController->ReadData(true);
                this->logger->LogInfo(testResponse.c_str());
            }
        }
        
    }
}

bool CommsGSMDeviceDriver::SendImage(CameraImage data, string number)
{
    string testResponse;
    
    if (this->isInitialised)
    {
        if (data.image != nullptr)
        {
            auto commandList = this->atCommandController->SendMMSCommandSequence(data, number);
            std::vector<ATCommand>::iterator iter = commandList.begin();
            auto fialedResponse = false;
            
            while (iter != commandList.end() && !fialedResponse)
            {
                auto command = *iter;
                
                if (command.Payload == nullptr)
                {
                    this->portController->SendData(command.Command.c_str());
                }  
                else
                {
                    this->portController->SendByteStream(command.Payload->image, command.Payload->size);
                }
                
                testResponse = this->portController->ReadData(true);
                if (!this->stringParser->HasString(testResponse,command.ExpectedResponse))
                {    
                    fialedResponse = true;
                }
                
                iter++;
            }
        }
    }
} 