#include "CommandController.h"

CommandController::CommandController()
{
    this->isInitialised = false;
}

void CommandController::Initialise()
{
    //Create a command queue and empty.
    while(!this->commandQueue.empty()) 
        this->commandQueue.pop();
        
    this->isInitialised = true;
    
}

void CommandController::WriteCommand(Command command)
{
    this->commandQueue.push(command);
}

Command CommandController::GetCommand()
{
    Command command;
    
    if (!this->commandQueue.empty())
    {
        command = this->commandQueue.front();
        this->commandQueue.pop();
    }
    
    return command;
}