#ifndef IReadCommandController_H
#define IReadCommandController_H
#include "Command.h"

class IReadCommandController
{
public:
    virtual Command GetCommand() = 0; 
};
#endif