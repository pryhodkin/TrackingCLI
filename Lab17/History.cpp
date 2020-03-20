//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#include "History.h"

History::History()
{
    isOn = true;
    savedPointer = 0;
}

bool History::Clear()
{
    history.clear();
    savedPointer = 0;
    return true;
}

bool History::Write(Command command)
{
    history.push_back(command);
    return true;
}

std::string History::ToString(int bottomBound) {
    std::string result = "";
    for(unsigned long i = bottomBound; i < history.size(); i++)
        result += history[i].ToString() + "\n\n";
    return result;
}

bool History::IsOn()
{
    return isOn;
}

void History::IsOn(bool set)
{
    isOn = set;
}

int History::SavedPointer()
{
    return savedPointer;
}

void History::SavedPointer(int set)
{
    savedPointer = set;
}

int History::Size()
{
    history.size();
}
