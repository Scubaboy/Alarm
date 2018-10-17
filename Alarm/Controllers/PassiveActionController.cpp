#include "PassiveActionController.h"

PassiveActionController::PassiveActionController(ICameraController* cameraController, 
                                                 ICommsController* commsController)
{
    this->cameraController = cameraController;
    this->commsController = commsController;
}

void PassiveActionController::Update(Action operatorRequestedAction)
{
    if (operatorRequestedAction == Action::TakeImage)
    {
        auto imageData = this->cameraController->GrabImage();
        
        this->commsController->SendImage(imageData,"07725589216");
        
        delete[] imageData.image;
    }
}