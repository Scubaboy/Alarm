#ifndef IGPIOController_H
#define IGPIOController_H

class IGPIOController 
{
public:
    virtual void Initialise() = 0;
    virtual void pinModel (int pin, int mode) = 0;
    virtual void DigitalWrite(int pin, int value) = 0;
    virtual void pullUpDnControlGPIOl (int pin, int pud) = 0; 
};
#endif