#ifndef IPortController_H
#define IPortController_H
#include <string>

using namespace std;

class IPortController
{
public:
    virtual void OpenPort(const char* device, int baud) = 0;
    virtual void SendData(const char* data, const char* terminate = "\r") = 0;
    virtual void SendByteStream(const unsigned char* data, int size) = 0;
    virtual string ReadData(bool wait = false) = 0;
};
#endif