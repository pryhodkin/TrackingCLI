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
public:
    explicit Command(const std::string& line);

    const std::string& GetCommand()               const;    //getter for field 'command'
    const std::vector<std::string>& GetArguments()const;    //getter for field 'arguments'
    std::string ToString()                        const;    //converts command to string "'datetime'\t-\t'command'"

private:
    static std::vector<std::string> splitArguments(const std::string& line); //splits string to vector of words
    static std::string DatetimeToString(const std::tm& time);                //format: yyyy.mm.dd hh:mm:ss

private:
    std::string command;                        //first word from line
    std::vector<std::string> arguments;         //other words
    std::string datetime;                       //date & time when command was entered

};

#endif //LAB17_COMMAND_H
