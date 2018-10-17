#ifndef IActionController_H
#define IActionController_H
#include "SystemCommands.h"

class IActionController
{
public:
    virtual void Update(Action operatorRequestedAction) = 0;
};
#endif