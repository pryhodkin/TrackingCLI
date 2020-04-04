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
    std::string command;                        //first word from line
    std::vector<std::string> arguments;         //other words
    std::string datetime;                       //date & time when command was entered

public:
    Command(const std::string& line);

    std::string GetCommand();                   //getter for field 'command'
    std::vector<std::string> GetArguments();    //getter for field 'arguments'
    std::string ToString() const;               //converts command to string "'datetime'\t-\t'command'"

private:
    static std::vector<std::string> splitArguments(const std::string& line); //splits string to vector of words
    static std::string DatetimeToString(std::tm time);                //format: yyyy:mm:dd:hh:mm:ss
};

#endif //LAB17_COMMAND_H
