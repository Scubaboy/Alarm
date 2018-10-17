#include "IRCamera.h"
#include <ctime>
#include <unistd.h>

IRCamera::IRCamera(int width, int depth, ILogger* logger)
{
    this->depth = depth;
    this->width = width;
    this->logger = logger;
    this->initialised = false;
}

void IRCamera::Initialise()
{
    bool isOpen = this->camera.open();
    
    this->initialised = false;
    
    if (!isOpen)
    {
        this->logger->LogError("Failed to open camera!!");
    }
    else
    {
        this->logger->LogInfo("Camera opened wating 3 seconds to allow camera to sync....");
        sleep(3);
        this->initialised = true;
    }
}

/*
 * Captures an image from the camera, the caller needs to deallocate any allocated memory.
 */
unsigned char* IRCamera::CaptureImage()
{
    unsigned char* data = nullptr;
    
    if (this->initialised)
    {
        //Capture image.
        this->camera.grab();
    
        //Allocate memory for the image.
        data = new unsigned char[this->camera.getImageTypeSize(RASPICAM_FORMAT_RGB)];
    
        //Extract image into the rgb buffer.
        this->camera.retrieve(data, RASPICAM_FORMAT_RGB);
    }
    
    return data;
}