#include "ATCommand.h"

ATCommand::ATCommand(std::string command, std::string expectedResponse)
{
    this->Command = command;
    this->ExpectedResponse = expectedResponse;
}