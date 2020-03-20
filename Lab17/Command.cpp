//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#include "Command.h"

#include <utility>
#include <sstream>

Command::Command(std::string line)
{
    std::vector<std::string> args = splitArguments(std::move(line));
    if(!args.empty())
    {
        command = args[0];
        for (int i = 1; i < args.size(); i++)
            arguments.push_back(args[i]);
    }
    std::time_t now = std::time(NULL);
    std::tm time = *std::localtime(&now);
    datetime = DatetimeToString(time);
}

std::string Command::GetCommand()
{
    return command;
}

std::vector<std::string> Command::GetArguments()
{
    return arguments;
}

std::string Command::ToString() const
{
    std::string result = datetime + "\t-\t" + command + (command == "log"? " " + (arguments[0] == "history"? arguments[0] + " " + arguments[1]: arguments[0]):"");
    return result;
}

std::vector<std::string> Command::splitArguments(std::string line)
{
    std::stringstream stream(line);
    std::vector<std::string> result;
    for(std::string str; stream >> str;)
        result.push_back(str);
    return result;
}

std::string Command::DatetimeToString(std::tm time)
{
    std::stringstream result;
    result << 1900 + time.tm_year << ":";
    result << (time.tm_mon < 9 ? "0": "") << 1 + time.tm_mon << ":";
    result << (time.tm_mday < 10? "0": "") << time.tm_mday << ":";
    result << (time.tm_hour< 10? "0": "") << time.tm_hour << ":";
    result << (time.tm_min < 10? "0": "") << time.tm_min << ":";
    result << (time.tm_sec < 10? "0": "") << time.tm_sec;
    return result.str();
}




