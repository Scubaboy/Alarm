#ifndef CommsGSMDeviceDriver_H
#define CommsGSMDeviceDriver_H
#include "ICommsDeviceDriver.h"
#include "ILogger.h"
#include "IPortController.h"
#include "IGPIOController.h"
#include "IStringResponseParser.h"
#include "IATCommandSequenceController.h"

class CommsGSMDeviceDriver : public ICommsDeviceDriver
{
public:
    CommsGSMDeviceDriver(ILogger* logger, 
                         IPortController* portController, 
                         IGPIOController* gpioController, 
                         IStringResponseParser* stringParser,
                         IATCommandSequenceController* atCommandController);
    void Initialise();
    bool SendMsg(string msg, string number);
    bool SendImage(CameraImage image, string number);  
    ReceivedMessage GetNextMsg();
private:
    ILogger* logger;
    IPortController* portController;
    IGPIOController* gpioController;
    IStringResponseParser* stringParser;
    IATCommandSequenceController* atCommandController;
    bool isInitialised;
};
#endif