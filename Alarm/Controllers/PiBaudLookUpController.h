#ifndef PiBaudLookUpController_H
#define PiBaudLookUpController_H
#include "IBaudLookUpController.h"

class PiBaudLookUpController : public IBaudLookUpController
{
    public:
        speed_t GetConvertedBaud(int requestBaud);
};
#endif