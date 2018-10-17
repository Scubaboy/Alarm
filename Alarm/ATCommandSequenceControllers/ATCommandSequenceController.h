#ifndef ATCommandSequenceController_H
#define ATCommandSequenceController_H
#include "IATCommandSequenceController.h"

class ATCommandSequenceController : public IATCommandSequenceController
{
public:
    std::vector<ATCommand> SendMMSCommandSequence(CameraImage cameraImage, std::string number); 
    std::vector<ATCommand> SendSMSCommandSequence(std::string message, std::string number);
};
#endif