#ifndef ILogger_h
#define ILogger_h
#include <string>

using namespace std;

class ILogger
{
public:
    bool virtual Initialise() = 0;
    void virtual LogWarning(string msg) = 0;
    void virtual LogError(string msg) = 0;
    void virtual LogInfo(string msg) = 0;
};
#endif