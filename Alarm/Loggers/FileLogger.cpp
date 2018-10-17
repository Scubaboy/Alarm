#include "FileLogger.h"
#include <sstream>
#include <iomanip>
#include <ctime>

FileLogger::FileLogger(string logFilePath, string logFileName)
{
    this->logFileName = logFileName;
    this->logFilePath = logFilePath;
    this->isInitialised = false;
}

bool FileLogger::Initialise()
{
    stringstream filenamePath; 
    filenamePath << this->logFilePath << this->logFileName;
    this->logFile.open(filenamePath.str().c_str(),ios::trunc);
    this->isInitialised = true;
    
    return this->isInitialised;
}

void FileLogger::LogWarning(string msg)
{
    stringstream msgToWrite;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    
    msgToWrite << put_time(&tm, "%d-%m-%Y %H-%M-%S ")  << "Warning - " << msg;
    this->logFile << msgToWrite.str() << "\n\r" ;
}

void FileLogger::LogError(string msg)
{
    stringstream msgToWrite;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    
    msgToWrite << put_time(&tm, "%d-%m-%Y %H-%M-%S ") << "Error - " << msg;
    this->logFile << msgToWrite.str() << "\n\r" ;
}

void FileLogger::LogInfo(string msg)
{
    stringstream msgToWrite;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    
    msgToWrite << put_time(&tm, "%d-%m-%Y %H-%M-%S ")  << "Info - " << msg;
    this->logFile << msgToWrite.str() << "\n\r" ;
}