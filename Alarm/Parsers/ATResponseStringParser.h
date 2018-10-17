#ifndef ATResponseStringParser_H
#define ATResponseStringParser_H
#include "IStringResponseParser.h"

class ATResponseStringParser : public IStringResponseParser
{
public:
    bool HasString(std::string source, std::string lookup);
    ReceivedMessage BuildMessage(std::string rawMessage); 
};
#endif