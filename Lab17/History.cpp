//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#include "History.h"

History::History()
{
    isOn = true;        //default is true
    savedPointer = 0;   //we haven't saved any records to logfile yet
}

bool History::Clear()
{
    history.clear();    //delete all records from history
    savedPointer = 0;   //we haven't saved any records to logfile yet
    return true;
}

bool History::Write(const Command& command)
{
    history.push_back(command);
    return true;
}

std::string History::ToString(int bottomBound)
{
    std::string result = "";
    for(unsigned long i = bottomBound; i < history.size(); i++) //simple iterate
        result += history[i].ToString() + "\n\n";
    return result;
}

bool History::IsOn() const
{
    return isOn;
}

void History::IsOn(bool set)
{
    isOn = set;
}

int History::SavedPointer() const
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
