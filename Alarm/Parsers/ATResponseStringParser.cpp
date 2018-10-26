#include "ATResponseStringParser.h"
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <vector>
#include <regex>
#include "SystemCommands.h"

bool ATResponseStringParser::HasString(std::string source, std::string lookup)
{
    return source.find(lookup) != std::string::npos;
}

ReceivedMessage ATResponseStringParser::BuildMessage(std::string rawMessage)
{
    ReceivedMessage recvMsg;
    std::string delims = "\r\n";
    std::string comma = ",";
    std::vector<std::string> line_parts;
    std::vector<std::string> headerParts;
    boost::algorithm::split_regex(line_parts, rawMessage, boost::regex(delims));
    boost::algorithm::split(headerParts, line_parts[1],boost::is_any_of(comma));
    
    if (line_parts.size() >= 6 )
    {
        recvMsg = ReceivedMessage(line_parts[2],headerParts[4]+headerParts[5],headerParts[2]);
    }
    
    return recvMsg;
}

Command ATResponseStringParser::BuildCommand(ReceivedMessage msg)
{
    std::string pipe = ":";
    std::string text = msg.Message();
    std::vector<std::string> parts;
    boost::algorithm::split(parts, text, boost::is_any_of(pipe));
    Command command;
    Mode mode;
    Action action;
    
    if (parts.size() == 3)
    {
        //extract pin
        auto pin = parts[0];
        
        if (parts[1].compare("EnterActive") == 0)
        {
            mode = Mode::EnterActive;
        }
        else if (parts[1].compare("EnterPassive") == 0)
        {
            mode = Mode::EnterPassive;
        }
        else
        {
            mode = Mode::NoCommand;
        }
        
        if (parts[2].find("TakeImage") != std::string::npos)
        {
            action = Action::TakeImage;
        }
        else
        {
            action = Action::NoAction;
        }
        
        command = Command(mode, action);
    }
    
    return command;
}