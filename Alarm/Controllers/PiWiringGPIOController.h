#ifndef PiWiringGPIOController_H
#define PiWiringGPIOController_H
#include "IGPIOController.h"
#include "ILogger.h"

class PiWiringGPIOController : public IGPIOController
{
public:
    PiWiringGPIOController(ILogger* logger);
    void Initialise();
    void pinModel (int pin, int mode);
    void DigitalWrite(int pin, int value);
    void pullUpDnControlGPIOl (int pin, int pud); 
private:
    ILogger* logger;
};
#endif