/*Author: Robin Cawsey
 *Description: Constructs the PIRSensor class.
 */
#include "PIRSensor.h"
#include <wiringPi.h>

using namespace std;

const int PIRInputGPIOPin = 7;

//Creates a new instance of the PIRSensor object.
PIRSensor::PIRSensor()
{
    this->isInitialised = false;
}

//Initialises the GPIO and sensor pin connections.
void PIRSensor::Initialise()
{
    wiringPiSetup();
    pinMode(PIRInputGPIOPin, INPUT);
    
    this->isInitialised = true;
}

//Reads a value from the sensor, if the output from the sensor
//is High then motion has been detected.
PIRSensorType PIRSensor::ReadSensor()
{
    PIRSensorType data;
    
    data.IsActive = false;
    
    if (this->isInitialised)
    {
        int readValue = digitalRead(PIRInputGPIOPin);
        
        data.IsActive = true;
        data.IsTripped = readValue == HIGH ? true : false;
    }
    
    return data;
}