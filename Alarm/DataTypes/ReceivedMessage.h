#ifndef ReceivedMessage_H
#define ReceivedMessage_H
#include <string>
#include <time.h>

class ReceivedMessage
{
public:
    ReceivedMessage();
    ReceivedMessage (std::string message, std::string dateTime, std::string number);
    std::string Message();
    std::string DateTime();
    std::string Number();
private:
    std::string message;
    std::string dateTime;
    std::string number;
    
};
#endif