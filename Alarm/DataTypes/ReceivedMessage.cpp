#include "ReceivedMessage.h"

ReceivedMessage::ReceivedMessage()
{
    this->isValid = false;
}
ReceivedMessage::ReceivedMessage (std::string message, std::string dateTime, std::string number)
{
    this->message = message;
    this->number = number;
    this->dateTime = dateTime;
    this->isValid = true;
}
    
std::string ReceivedMessage::Message()
{
    return this->message;
}

std::string ReceivedMessage::DateTime()
{
    return this->dateTime;
}
    
std::string ReceivedMessage::Number()
{
    return this->number;
}

bool ReceivedMessage::IsValid()
{
    return this->isValid;
}