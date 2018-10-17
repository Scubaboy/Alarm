#include "ATCommandSequenceController.h"

std::vector<ATCommand> ATCommandSequenceController::SendMMSCommandSequence(CameraImage cameraImage, 
                                                                           std::string number)
{
    std::vector<AtCommands> commands = 
    {
        ATCommand("AT+CMMSINIT","OK"), 
        ATCommand()
    };

    
    return commands
}
 

std::vector<ATCommand> ATCommandSequenceController::SendSMSCommandSequence(std::string message, 
                                                                           std::string number)
{
    
}