#ifndef ICommsController_H
#define ICommsController_H
#include <string>
#include "CameraImage.h"

using namespace std;

class ICommsController
{
public:
    virtual void Initialise() = 0;
    virtual bool SendMsg(string msg, string number) = 0;
    virtual bool SendImage(CameraImage imageData, string number) = 0;
};
#endif