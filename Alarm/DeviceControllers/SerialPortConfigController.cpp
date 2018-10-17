#include "SerialPortConfigController.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <wiringPi.h>

SerialPortConfigController::SerialPortConfigController(IBaudLookUpController* baudLookUpController, ILogger* logger)
{
    this->baudLookUpController = baudLookUpController;
    this->logger = logger;
}

string SerialPortConfigController::ReadData(bool wait)
{
    string data;
    std::stringstream msgReceived;
    
    if (this->fileDevice != -1)
    {
        int dataReadSize = -1;
        bool startTicking = false;
        
        if (wait)
        {
            int ticksForComplete = 0;
            char databuffer[255];
            char* databufferptr = databuffer;
            
            memset(databuffer,0,255);
            
            while (ticksForComplete < 10)
            {                
                if (ioctl(this->fileDevice, FIONREAD, &dataReadSize) != -1)
                {
                    if (dataReadSize > 0)
                    {                        
                        read(this->fileDevice,databufferptr,dataReadSize);
                        
                        startTicking = true;
                        databufferptr+= dataReadSize;
                        ticksForComplete = 0;
                    }
                    
                    if (startTicking)
                    {
                        delay(10);
                        ticksForComplete++;
                    }
                }
            }
            
            data = string(databuffer);//msgReceived.str();
        }
        else
        {
            
            if (ioctl (this->fileDevice, FIONREAD, &dataReadSize) != -1)
            {
                char databuffer[dataReadSize];
            
                read(this->fileDevice,databuffer,dataReadSize);
            
                data = string(databuffer);
            }
        
        }
    }
    
    return data;
}

void SerialPortConfigController::SendByteStream(const unsigned char* data, int size)
{
    if (this->fileDevice != -1)
    {
        write(this->fileDevice,data,size);

    }
}

void SerialPortConfigController::SendData(const char* data, const char* terminate = "\r")
{
    if (this->fileDevice != -1)
    {
        write(this->fileDevice,data,strlen(data));
        write(this->fileDevice,terminate,strlen(terminate));
    }
}

void SerialPortConfigController::OpenPort(const char* device, int baud)
{
    struct termios options;
    int convertedBaud = -2;
    int status;
    stringstream msgToWrite;
    
    convertedBaud = this->baudLookUpController->GetConvertedBaud(baud);
    
    if ((this->fileDevice = open(device, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK)) != -1)
    {
        fcntl (this->fileDevice, F_SETFL, O_RDWR) ;
        tcgetattr (this->fileDevice, &options) ;
        cfmakeraw   (&options) ;
        cfsetispeed (&options, convertedBaud) ;
        cfsetospeed (&options, convertedBaud) ;

        options.c_cflag |= (CLOCAL | CREAD) ;
        options.c_cflag &= ~PARENB ;
        options.c_cflag &= ~CSTOPB ;
        options.c_cflag &= ~CSIZE ;
        options.c_cflag |= CS8 ;
        options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG) ;
        options.c_oflag &= ~OPOST ;

        options.c_cc [VMIN]  =   0 ;
        options.c_cc [VTIME] = 100 ;

        tcsetattr (this->fileDevice, TCSANOW | TCSAFLUSH, &options) ;
        ioctl (this->fileDevice, TIOCMGET, &status);
        status |= TIOCM_DTR ;
        status |= TIOCM_RTS ;
        ioctl (this->fileDevice, TIOCMSET, &status);
        usleep (10000);
        
        msgToWrite << "Comms port device: " << device << " Open";
        this->logger->LogInfo(msgToWrite.str());
    }
    else
    {
        msgToWrite << "Comms port device: " << device << " failed open!";
        this->logger->LogInfo(msgToWrite.str());
    }
}