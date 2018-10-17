#include "SystemStateCmdController.h"
#include "Command.h"

SystemStateCmdController::SystemStateCmdController(IReadCommandController* readCommandController, 
                             IActionController* activeActionController, 
                             IActionController* passiveActionController,
                             ILogger* logger)
{
    this->readCommandController = readCommandController;
    this->activeActionController = activeActionController;
    this->passiveActionController = passiveActionController;
    this->logger = logger;
}
    
void SystemStateCmdController::Update()
{
    if (this->isInitialised)
    {
        Command command = this->readCommandController->GetCommand();
    
        switch (command.GetMode())
        {
            case Mode::EnterActive:
            {
                this->activeController = this->activeActionController;
                break;
            }
            case Mode::EnterPassive:
            {
                this->activeController = this->passiveActionController;
                break;
            }
            case Mode::NoCommand:
            {
                break;
            }
        }
    
        //Run active controller update.
        this->activeController->Update(command.GetAction());
    
    }
}
    
void SystemStateCmdController::Initialise()
{
    if (this->readCommandController != nullptr && this->activeActionController != nullptr
    && this->passiveActionController != nullptr)
    {
        this->isInitialised = true;
        this->logger->LogInfo("SystemStateCmdController initialised.");
        this->activeController = this->passiveActionController;
    }
    else
    {
        this->logger->LogError("Failed to intialise SystemStateCmdController.");
    }
}