#ifndef ICameraController_H
#define ICameraController_H
#include "CameraImage.h"

class ICameraController
{
public:
    virtual void Initialise() = 0;
    virtual CameraImage GrabImage() = 0;
};
#endif