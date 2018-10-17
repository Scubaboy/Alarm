#ifndef SerialPortConfigController_H
#define SerialPortConfigController_H
#include "IPortController.h"
#include "IBaudLookUpController.h"
#include "ILogger.h"

class SerialPortConfigController : public IPortController
{
public:
    SerialPortConfigController(IBaudLookUpController* baudLookUpController, ILogger* looger);
    void OpenPort(const char* device, int baud);
    void SendData(const char* data, const char* terminate);
    void SendByteStream(const unsigned char* data, int size);
    string ReadData(bool wait = false);
private:
    IBaudLookUpController* baudLookUpController;
    ILogger* logger;
    int fileDevice;
};
#endif