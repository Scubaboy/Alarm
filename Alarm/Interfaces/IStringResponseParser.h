#ifndef IStringResponseParser_H
#define IStringResponseParser_H
#include <string>
#include "ReceivedMessage.h"

class IStringResponseParser
{
public:
    bool virtual HasString(std::string source, std::string lookup) = 0;
    ReceivedMessage virtual BuildMessage(std::string rawMessage) = 0;
};
#endif