//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#include "Command.h"

#include <sstream>

Command::Command(const std::string& line)
{
    std::vector<std::string> args = splitArguments(line);
    if(!args.empty())
    {
        command = args[0];                      //first word is our command
        for (int i = 1; i < args.size(); i++)   //all other words are arguments
            arguments.push_back(args[i]);
    }
    std::time_t now = std::time(nullptr);   //taking current time
    std::tm time = *std::localtime(&now);
    datetime = DatetimeToString(time);          //conversion time to string
}

const std::string& Command::GetCommand() const
{
    return command;
}

const std::vector<std::string>& Command::GetArguments() const
{
    return arguments;
}

std::string Command::ToString() const
{             //if command is 'log' we should return to string also a few next words that are in arguments
    std::string result = datetime + "\t-\t" + command;
    if(command == "log")
    {
        for(const auto & argument : arguments)
            result += ' ' + argument;
    }
    return result;
}

std::vector<std::string> Command::splitArguments(const std::string& line)
{
    std::stringstream stream(line);
    std::vector<std::string> result;
    for(std::string str; stream >> str;)
        result.push_back(str);
    return result;
}

std::string Command::DatetimeToString(const std::tm& time)
{
    std::stringstream result;               //to save every datetime in the same string format we write zeros
    result << 1900 + time.tm_year << ".";   //in the front of value if it's necessary
    result << (time.tm_mon  < 9 ? "0": "") << 1 + time.tm_mon << ".";
    result << (time.tm_mday < 10? "0": "") << time.tm_mday << " ";
    result << (time.tm_hour < 10? "0": "") << time.tm_hour << ":";
    result << (time.tm_min  < 10? "0": "") << time.tm_min  << ":";
    result << (time.tm_sec  < 10? "0": "") << time.tm_sec;
    return result.str();
}




