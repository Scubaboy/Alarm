#include "CommsGSMDeviceDriver.h"
#include <wiringPi.h>
#include <unistd.h>
#include <sstream>
#include "ReceivedMessage.h"

CommsGSMDeviceDriver::CommsGSMDeviceDriver(ILogger* logger, 
                                           IPortController* portController, 
                                           IGPIOController* gpioController, 
                                           IStringResponseParser* stringParser)
{
   this->logger = logger;
   this->portController = portController;
   this->gpioController = gpioController;
   this->stringParser = stringParser;
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
        string testResponse;
        
        this->portController->SendData("AT+CMGF=1");
        testResponse = this->portController->ReadData(true);
        if (this->stringParser->HasString(testResponse,"OK"))
        {
            this->portController->SendData("AT+CMGL=\"REC UNREAD\"");
            testResponse = this->portController->ReadData(true);
            this->logger->LogInfo(testResponse);
            msg = this->stringParser->BuildMessage(testResponse);
            
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
            //Initialise modem for MMS function
            /*this->portController->SendData("AT+CGDCONT?");
            this->portController->SendData("AT+CGATT=1");
            this->portController->SendData("AT+CGDATA=?");
            this->portController->SendData("AT+CGACT=1");*/
            this->portController->SendData("AT+CMMSINIT");
            testResponse = this->portController->ReadData(true);
            if (this->stringParser->HasString(testResponse,"OK"))
            {
                //Set mms url
                this->portController->SendData("AT+CMMSCURL=\"mmsc.mms.o2.co.uk:8002\"");
                testResponse = this->portController->ReadData(true);
                if (this->stringParser->HasString(testResponse,"OK"))
                {
                    //Set the bearer
                    this->portController->SendData("AT+CMMSCID=1");
                    testResponse = this->portController->ReadData(true);
                    
                    if (this->stringParser->HasString(testResponse,"OK"))
                    {
                        //Set MMS Proxy
                        this->portController->SendData("AT+CMMSPROTO=\"82.132.254.1\",8080");
                        testResponse = this->portController->ReadData(true);
                    
                        if (this->stringParser->HasString(testResponse,"OK"))
                        {
                            //Set PDU parameters
                           // this->portController->SendData("AT+CMMSSENDCFG=6,3,0,0,2,4");
                           // testResponse = this->portController->ReadData(true);
                    
                           //if (this->stringParser->HasString(testResponse,"OK"))
                            //{
                                //Set GPRS
                                this->portController->SendData("AT+SAPBR=3,1,\"Contype\",\"GPRS\"");
                                testResponse = this->portController->ReadData(true);
                                
                                if (this->stringParser->HasString(testResponse,"OK"))
                                {
                                    //Set APN
                                    this->portController->SendData("AT+SAPBR=3,1,\"APN\",\"payandgo.o2.co.uk\"");
                                    testResponse = this->portController->ReadData(true);
                                
                                    
                                    if (this->stringParser->HasString(testResponse,"OK"))
                                    {
                                        this->portController->SendData("AT+SAPBR=3,1,\"USER\",\"payandgo\"");
                                        testResponse = this->portController->ReadData(true);
                                
                                        if (this->stringParser->HasString(testResponse,"OK"))
                                        {
                                           this->portController->SendData("AT+SAPBR=3,1,\"PWD\",\"password\"");
                                            testResponse = this->portController->ReadData(true);
                                    
                                            if (this->stringParser->HasString(testResponse,"OK"))
                                            { 
                                            
                                                //Set Active bearer
                                                this->portController->SendData("AT+SAPBR=1,1");
                                                testResponse = this->portController->ReadData(true);
                                        
                                                if (this->stringParser->HasString(testResponse,"OK"))
                                                {
                                                    this->portController->SendData("AT+SAPBR=2,1");
                                                    testResponse = this->portController->ReadData(true);
                                        
                                                    if (this->stringParser->HasString(testResponse,"+SAPBR"))
                                                    {
                                                        this->portController->SendData("AT+CMMSEDIT=1");
                                                        testResponse = this->portController->ReadData(true);
                                        
                                                        if (this->stringParser->HasString(testResponse,"OK"))
                                                        {
                                                            stringstream msgToWrite;
                                                            msgToWrite << "AT+CMMSDOWN=\"PIC\"," << data.size << ",2000000";//,\"Test.jpg\"";
                                                            this->portController->SendData(msgToWrite.str().c_str());
                                                            testResponse = this->portController->ReadData(true);
                                        
                                                            if (this->stringParser->HasString(testResponse,"CONNECT"))
                                                            {
                                                                this->portController->SendByteStream(data.image, data.size);
                                                                testResponse = this->portController->ReadData(true);
                                        
                                                                if (this->stringParser->HasString(testResponse,"OK"))
                                                                {
                                                                     
                                                                     this->portController->SendData("AT+CMMSRECP=\"07725589216\"");
                                                                    testResponse = this->portController->ReadData(true);
                                        
                                                                    if (this->stringParser->HasString(testResponse,"OK"))
                                                                    {
                                                                        this->portController->SendData("AT+CMMSVIEW");
                                                                        testResponse = this->portController->ReadData(true);
                                        
                                                                        if (this->stringParser->HasString(testResponse,"CMMSVIEW"))
                                                                        {
                                                                            this->portController->SendData("AT+CMMSSEND");
                                                                            testResponse = this->portController->ReadData(true);
                                        
                                                                            if (this->stringParser->HasString(testResponse,"OK"))
                                                                            {
                                                                                
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            
                                            }
                                        }
                                    }
                                    
                                }
                           // }
                        }
                    }
                }
            }
        }
    }
} 