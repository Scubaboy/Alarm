#ifndef IRCameraController_H
#define IRCameraController_H
#include "ICameraController.h"
#include "raspicam_still.h"
#include "CameraImage.h"

class IRCameraController: public ICameraController
{
public:
    IRCameraController(int imageWidth, int imageDepth);
    void Initialise();
    CameraImage GrabImage();
private:
    int imageWidth;
    int imageDepth;
    bool isInitialised;
    raspicam::RaspiCam_Still camera;
};
#endif