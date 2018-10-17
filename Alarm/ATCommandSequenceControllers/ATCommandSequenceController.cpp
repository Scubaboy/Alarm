#include "ATCommandSequenceController.h"
#include <sstream>

std::vector<ATCommand> ATCommandSequenceController::SendMMSCommandSequence(CameraImage cameraImage, 
                                                                           std::string number)
{
    std::stringstream msgImageToWrite;
    std::stringstream msgRecptToWrite;
    msgImageToWrite << "AT+CMMSDOWN=\"PIC\"," << cameraImage.size << ",2000000";
    msgRecptToWrite  << "AT+CMMSRECP=\"" << number << \";
                                                        
    std::vector<ATCommand> commands = 
    {
        ATCommand("AT+CMMSINIT","OK"), 
        ATCommand("AT+CMMSCURL=\"mmsc.mms.o2.co.uk:8002\"", "OK"),
        ATCommand("AT+CMMSCID=1","OK"),
        ATCommand("AT+CMMSPROTO=\"82.132.254.1\",8080","OK"),
        ATCommand("AT+SAPBR=3,1,\"Contype\",\"GPRS\"","OK"),
        ATCommand("AT+SAPBR=3,1,\"APN\",\"payandgo.o2.co.uk\"","OK"),
        ATCommand("AT+SAPBR=3,1,\"USER\",\"payandgo\"","OK"),
        ATCommand("AT+SAPBR=3,1,\"PWD\",\"password\"","OK"),
        ATCommand("AT+SAPBR=1,1","OK"),
        ATCommand("AT+SAPBR=2,1","+SAPBR"),
        ATCommand("AT+CMMSEDIT=1","OK"),
        ATCommand(msgImageToWrite.str(),"CONNECT"),
        ATCommand("","OK",cameraImage.image),
        ATCommand(msgRecptToWrite.str(),"OK"),
        ATCommand("AT+CMMSVIEW","CMMSVIEW"),
        ATCommand("AT+CMMSSEND","OK"),
        ATCommand("AT+CMMSTERM","OK"),
    };

    
    return commands
}
 

std::vector<ATCommand> ATCommandSequenceController::SendSMSCommandSequence(std::string message, 
                                                                           std::string number)
{
    
}