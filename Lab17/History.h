//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#ifndef LAB17_HISTORY_H
#define LAB17_HISTORY_H

#include "Command.h"

class History
{
private:
    std::vector<Command> history;       //field that contains all records in history
    bool isOn;                          //should we write to history or not
    int savedPointer;                   //index of record that we should save to logfile at first

public:
    History();

    bool Clear();                           //clearing the history
    bool Write(const Command& command);     //write some Command to history
    std::string ToString(int bottomBound);  //conversion to string from some exact bottom bound till the end of history

    bool IsOn();                        //getter for 'isOn'
    void IsOn(bool set);                //setter for 'isOn'

    int SavedPointer();                 //getter for 'savedPointer'
    void SavedPointer(int set);         //setter for 'savedPointer'

    int Size();                         //size of history (number of records)
};

#endif //LAB17_HISTORY_H
