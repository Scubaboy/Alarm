#ifndef PassiveActionController_H
#define PassiveActionController_H
#include "IActionController.h"
#include "ICameraController.h"
#include "ICommsDeviceDriver.h"

class PassiveActionController : public IActionController
{
public:
    PassiveActionController(ICameraController* cameraController, ICommsDeviceDriver* commsController);
    void Update(Action operatorRequestedAction);
private:
    ICameraController* cameraController;
    ICommsDeviceDriver* commsController;
};
#endif