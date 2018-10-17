//Defines the characteristics of a PIR Sensor.
#ifndef IPIRSensor_h
#define IPIRSensor_h

#include "ISensor.h"
#include "PIRSensorType.h"

class PIRSensor : public ISensor<PIRSensorType>
{
public:
    PIRSensor();
    PIRSensorType ReadSensor(); 
    void Initialise();
private:
    bool isInitialised;
};

#endif