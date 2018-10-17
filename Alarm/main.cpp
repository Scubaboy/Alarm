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

int main(int argc, char **argv)
{
    ATResponseStringParser atStringParser;
    FileLogger fileLogger = FileLogger("/home/pi/AlarmLogs/","AlarmLog.txt");
    ILogger* logger = &fileLogger;
    PiBaudLookUpController baudController;
    PiWiringGPIOController gpioController = PiWiringGPIOController(&fileLogger);
    SerialPortConfigController portController = SerialPortConfigController(&baudController, &fileLogger);
    CommsGSMDeviceDriver gsmDriver = CommsGSMDeviceDriver(&fileLogger,&portController,&gpioController, &atStringParser);
    IRCameraController irCamera = IRCameraController(176,208);
    ICameraController* camera = &irCamera;
    
    gpioController.Initialise();
    logger->Initialise();
    gsmDriver.Initialise();
    camera->Initialise();
    CameraImage imageData;
    
    imageData = camera->GrabImage();
    gsmDriver.SendImage(imageData,"07725589216");
    //gpioController.Initialise();
    //logger->Initialise();
    //gsmDriver.Initialise();
    //auto mesg = gsmDriver.GetNextMsg();
    //gsmDriver.SendMsg("BALANCE","20202");
    //raspicam::RaspiCam camera;
    //PIRSensor mySensor;
    //PIRSensorType data = mySensor.ReadSensor();
    
	//printf("hello world\n");
	return 0;
}
