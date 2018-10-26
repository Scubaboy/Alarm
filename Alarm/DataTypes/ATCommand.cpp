#include "ATCommand.h"

ATCommand::ATCommand(std::string command, std::string expectedResponse, CameraImage* payload)
{
    this->Command = command;
    this->ExpectedResponse = expectedResponse;
    this->Payload = payload;
}

ATCommand::ATCommand(std::string command, std::string expectedResponse)
{
    this->Command = command;
    this->ExpectedResponse = expectedResponse;
    this->Payload = nullptr;
}