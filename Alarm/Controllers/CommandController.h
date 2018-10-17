#ifndef CommandController_H
#define CommandController_H
#include "IReadCommandController.h"
#include "IWriteCommandController.h"
#include <queue>

using namespace std;

class CommandController : public IReadCommandController, IWriteCommandController
{
public:
    CommandController();
    void WriteCommand(Command command);
    Command GetCommand();
    void Initialise();
private:
    bool isInitialised;
    queue<Command> commandQueue;
};
#endif