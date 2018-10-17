//External camera interface definition.
#ifndef ICamera_h
#define ICamera_h

using namespace std;

class ICamera
{
public:
    virtual void Initialise() = 0;
    virtual unsigned char* CaptureImage() = 0;
};

#endif