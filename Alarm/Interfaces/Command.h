#ifndef Command_H
#define Command_H
#include "SystemCommands.h"

class Command
{
public:
    Command();
    Command(Mode mode, Action action);
    Mode GetMode();
    Action GetAction();
private:
    Mode mode;
    Action action;
};
#endif