#ifndef ATCommand_H
#define ATCommand_H
#include <string>

class ATCommand
{
public:
    ATCommand(std::string command, std::string expectedResponse);
    std::string Command;
    std::string ExpectedResponse;
    
};
#endif