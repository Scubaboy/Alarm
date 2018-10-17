#include "Command.h"

Command::Command()
{
        this->mode = Mode::NoCommand;
        this->action = Action::NoAction;
}

Command::Command(Mode mode, Action action)
{
    this->mode = mode;
    this->action = action;
}
Mode Command::GetMode()
{
    return this->mode;
}

Action Command::GetAction()
{
    return this->action;
}