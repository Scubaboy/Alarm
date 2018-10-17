#include "ReceivedMessage.h"

ReceivedMessage::ReceivedMessage()
{
    

}
ReceivedMessage::ReceivedMessage (std::string message, std::string dateTime, std::string number)
{
    this->message = message;
    this->number = number;
    this->dateTime = dateTime;
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