#ifndef PassiveActionController_H
#define PassiveActionController_H
#include "IActionController.h"
#include "ICameraController.h"
#include "ICommsController.h"

class PassiveActionController : public IActionController
{
public:
    PassiveActionController(ICameraController* cameraController, ICommsController* commsController);
    void Update(Action operatorRequestedAction);
private:
    ICameraController* cameraController;
    ICommsController* commsController;
};
#endif