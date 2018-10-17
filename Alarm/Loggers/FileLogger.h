#ifndef FileLogger_h
#define FileLogger_h
#include "ILogger.h"
#include <fstream>
#include <string>

using namespace std;

class FileLogger : public ILogger
{
public:
    FileLogger (string logFilePath, string logFileName);
    bool Initialise();
    void LogWarning(string msg);
    void LogError(string msg);
    void LogInfo(string msg);
private:
    string logFileName;
    string logFilePath;
    ofstream logFile;
    bool isInitialised;
};
#endif