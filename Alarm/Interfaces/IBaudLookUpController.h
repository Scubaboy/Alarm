#ifndef IBaudLookUpController_H
#define IBaudLookUpController_H
#include <termios.h>

class IBaudLookUpController
{
public:
    virtual speed_t GetConvertedBaud(int requestBaud) = 0;
};
#endif