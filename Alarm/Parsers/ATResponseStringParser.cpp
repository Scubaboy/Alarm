#include "ATResponseStringParser.h"
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <vector>
#include <regex>

bool ATResponseStringParser::HasString(std::string source, std::string lookup)
{
    return source.find(lookup) != std::string::npos;
}

ReceivedMessage ATResponseStringParser::BuildMessage(std::string rawMessage)
{
    std::string delims = "\r\n";
    std::string comma = ",";
    std::vector<std::string> line_parts;
    std::vector<std::string> headerParts;
    boost::algorithm::split_regex(line_parts, rawMessage, boost::regex(delims));
    boost::algorithm::split(headerParts, line_parts[1],boost::is_any_of(comma));
    
    return ReceivedMessage(line_parts[2],headerParts[4]+headerParts[5],headerParts[2]);
}