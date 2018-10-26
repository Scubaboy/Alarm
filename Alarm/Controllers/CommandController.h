#ifndef CommandController_H
#define CommandController_H
#include "IReadCommandController.h"
#include "IWriteCommandController.h"
#include <queue>

class CommandController : public IReadCommandController, IWriteCommandController
{
public:
    CommandController();
    void WriteCommand(Command command);
    Command GetCommand();
    void Initialise();
private:
    bool isInitialised;
    std::queue<Command> commandQueue;
};
#endif