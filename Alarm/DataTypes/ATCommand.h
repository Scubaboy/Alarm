#ifndef ATCommand_H
#define ATCommand_H
#include <string>
#include "CameraImage.h"
class ATCommand
{
public:
    ATCommand(std::string command, std::string expectedResponse, CameraImage* payload);
    ATCommand(std::string command, std::string expectedResponse);
    std::string Command;
    std::string ExpectedResponse;
    CameraImage* Payload;
    
};
#endif