#include "ActiveActionController.h"

ActiveActionController::ActiveActionController(ICameraController* cameraController, 
                           ICommsDeviceDriver* commsController, 
                           ISensor<PIRSensorType>* motionSensor)
{
    this->cameraController = cameraController;
    this->commsController = commsController;
    this->motionSensor = motionSensor;                          
}
    
void ActiveActionController::Update(Action operatorRequestedAction)
{
    if (operatorRequestedAction == Action::TakeImage)
    {
        auto imageData = this->cameraController->GrabImage();
        
        this->commsController->SendImage(imageData,"07725589216");
        delete[] imageData.image;
    }
    else if (operatorRequestedAction == Action::NoAction)
    {
        auto sensorData = this->motionSensor->ReadSensor();
        
        if (sensorData.IsActive)
        {
            if (sensorData.IsTripped)
            {
                auto imageData = this->cameraController->GrabImage();
        
                this->commsController->SendImage(imageData,"07725589216");
                delete[] imageData.image;
            }
        }
    }
}