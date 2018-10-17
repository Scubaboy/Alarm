#include "IRCameraController.h"
#include <unistd.h>
#include <fstream>
#include <iostream>

IRCameraController::IRCameraController(int imageWidth, int imageDepth)
{
    this->imageWidth = imageWidth;
    this->imageDepth = imageDepth;
    this->isInitialised = false;
}

void IRCameraController::Initialise()
{
    this->camera.setCaptureSize(this->imageWidth, this->imageDepth);
    this->camera.setEncoding(raspicam::RASPICAM_ENCODING_JPEG);
    this->camera.open();
    sleep(3);
    this->isInitialised = true;
}

CameraImage IRCameraController::GrabImage()
{
    CameraImage image;
    
    image.image = nullptr;
    image.size = this->camera.getImageBufferSize();
    
    image.image = new unsigned char[image.size];
    this->camera.grab_retrieve(image.image,image.size);

    return image;
}