//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#ifndef LAB17_COMMAND_H
#define LAB17_COMMAND_H

#include <string>
#include <vector>
#include <ctime>

class Command
{
private:
    std::string command;
    std::vector<std::string> arguments;
    std::string datetime;

public:
    Command(std::string line);

    std::string GetCommand();
    std::vector<std::string> GetArguments();
    std::string ToString() const;

private:
    std::vector<std::string> splitArguments(std::string line);
    std::string DatetimeToString(std::tm time);
};

#endif //LAB17_COMMAND_H
