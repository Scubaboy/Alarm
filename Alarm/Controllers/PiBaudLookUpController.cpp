#include "PiBaudLookUpController.h"

speed_t PiBaudLookUpController::GetConvertedBaud(int requestBaud)
{
    speed_t myBaud;
    
    switch (requestBaud)
    {
        case 50:
        {
            myBaud = B50;
            break;
        }
        case 75:
        {
            myBaud = B75;
            break;
        }
        case 110:
        {
            myBaud = B110;
            break;
        }
        case 9600:
        {
            myBaud = B9600;
            break;
        }
    }
    
    return myBaud;
}