#include <stdio.h>
#include "PIRSensor.h"
#include "PIRSensorType.h"
#include <raspicam/raspicam.h>
#include "ILogger.h"
#include "FileLogger.h"
#include "CommsGSMDeviceDriver.h"
#include "PiBaudLookUpController.h"
#include "PiWiringGPIOController.h"
#include "SerialPortConfigController.h"
#include "ATResponseStringParser.h"
#include "IRCameraController.h"
#include "ICameraController.h"
#include "CameraImage.h"
#include "IATCommandSequenceController.h"
#include "ATCommandSequenceController.h"
#include "CommandController.h"
#include "SystemStateCmdController.h"
#include "ActiveActionController.h"
#include "PassiveActionController.h"
#include "wiringPi.h"

int main(int argc, char **argv)
{
    PIRSensor pirSensor;
    ATResponseStringParser atStringParser;
    FileLogger fileLogger = FileLogger("/home/pi/AlarmLogs/","AlarmLog.txt");
    ATCommandSequenceController atCommandSequenceController;
    PiBaudLookUpController baudController;
    PiWiringGPIOController gpioController = PiWiringGPIOController(&fileLogger);
    SerialPortConfigController portController = SerialPortConfigController(&baudController, &fileLogger);
    CommsGSMDeviceDriver gsmDriver = CommsGSMDeviceDriver(&fileLogger,&portController,&gpioController, &atStringParser, &atCommandSequenceController);
    IRCameraController irCamera = IRCameraController(176,208);
    CommandController commandController;
    PassiveActionController passiveActionController = PassiveActionController(&irCamera, &gsmDriver);
    ActiveActionController activeActionController = ActiveActionController(&irCamera, &gsmDriver,&pirSensor);
    SystemStateCmdController systemStateCmdController = SystemStateCmdController (&commandController, 
                                                                                  &activeActionController, 
                                                                                  &passiveActionController, 
                                                                                  &fileLogger);
                                                   
    pirSensor.Initialise();                                               
    fileLogger.Initialise();
    irCamera.Initialise();
    commandController.Initialise();
    gpioController.Initialise();
    gsmDriver.Initialise();
    systemStateCmdController.Initialise();
    
    while (true)
    {
        auto receivedMsg = gsmDriver.GetNextMsg();
        
        if (receivedMsg.IsValid())
        {
            auto command = atStringParser.BuildCommand(receivedMsg);
            commandController.WriteCommand(command);
        }
        
        systemStateCmdController.Update();
        
        delay(200);
    }
    
    return 0;
}
