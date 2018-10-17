#ifndef IRCamera_h
#define IRCamera_h
#include "ICamera.h"
#include "ILogger.h"
#include <raspicam/raspicam.h>

using namespace std;
using namespace raspicam;

class IRCamera : public ICamera
{
public:
    IRCamera (int width, int depth, ILogger* logger);
    void Initialise();
    unsigned char* CaptureImage();
private:
    int width, depth;
    RaspiCam camera;
    ILogger* logger;
    bool initialised;
};

#endif