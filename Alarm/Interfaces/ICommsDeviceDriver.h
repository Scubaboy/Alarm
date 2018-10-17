#ifndef ICommsDeviceDriver_H
#define ICommsDeviceDriver_H
#include <string>
#include "ReceivedMessage.h"
#include "CameraImage.h"

using namespace std;

class ICommsDeviceDriver
{
public:
    virtual void Initialise() = 0;
    virtual bool SendMsg(string msg, string number) = 0;
    virtual bool SendImage(CameraImage image, string number) = 0;
    virtual ReceivedMessage GetNextMsg() = 0;
};
#endif