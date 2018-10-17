#include "PiWiringGPIOController.h"
#include <wiringPi.h>

PiWiringGPIOController::PiWiringGPIOController(ILogger* logger)
{
    this->logger = logger;
}

void PiWiringGPIOController::Initialise()
{
    wiringPiSetup();
}

void PiWiringGPIOController::DigitalWrite(int pin, int value)
{
    digitalWrite(pin,value);
}
void PiWiringGPIOController::pinModel (int pin, int mode)
{
    pinMode(pin, mode);
}

void PiWiringGPIOController::pullUpDnControlGPIOl (int pin, int pud)
{
    pullUpDnControl(pin, pud);
}