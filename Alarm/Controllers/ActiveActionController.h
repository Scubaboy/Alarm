#ifndef ActiveActionController_H
#define ActiveActionController_H
#include "IActionController.h"
#include "ICameraController.h"
#include "ICommsDeviceDriver.h"
#include "ISensor.h"
#include "PIRSensorType.h"

class ActiveActionController : public IActionController
{
  public:
    ActiveActionController(ICameraController* cameraController, 
                           ICommsDeviceDriver* commsController, 
                           ISensor<PIRSensorType>* motionSensor);
    void Update(Action operatorRequestedAction);
private:
    ICameraController* cameraController;
    ICommsDeviceDriver* commsController;  
    ISensor<PIRSensorType>* motionSensor;
};
#endif