#ifndef IWriteCommandController_h
#define IWriteCommandController_h
#include "Command.h"

class IWriteCommandController
{
public:
    virtual void WriteCommand(Command command) = 0;
};
#endif