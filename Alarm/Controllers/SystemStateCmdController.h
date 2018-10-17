#ifndef SystemStateCmdController_H
#define SystemStateCmdController_H
#include "ISystemStateController.h"
#include "IActionController.h"
#include "ILogger.h"
#include "IReadCommandController.h"

class SystemStateCmdController : public ISystemStateController
{
public:
    SystemStateCmdController(IReadCommandController* readCommandController, 
                             IActionController* activeActionController, 
                             IActionController* passiveActionController,
                             ILogger* logger);
    void Update();
    void Initialise();
private:
    bool isInitialised;
    IReadCommandController* readCommandController;
    IActionController* activeActionController;
    IActionController* passiveActionController;
    ILogger* logger;
    IActionController* activeController;
    
};
#endif