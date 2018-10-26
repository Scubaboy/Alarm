#ifndef IATCommandSequenceController_H
#define IATCommandSequenceController_H
#include <vector>
#include "CameraImage.h"
#include <string>
#include "ATCommand.h"

class IATCommandSequenceController
{
public:
    virtual std::vector<ATCommand> SendMMSCommandSequence(CameraImage cameraImage, std::string number) = 0; 
    virtual std::vector<ATCommand> SendSMSCommandSequence(std::string message, std::string number) = 0;
    virtual std::vector<ATCommand> ReadSMSCommandSequence() = 0;
};
#endif