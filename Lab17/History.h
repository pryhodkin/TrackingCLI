//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#ifndef LAB17_HISTORY_H
#define LAB17_HISTORY_H

#include "Command.h"

class History
{
private:
    std::vector<Command> history;
    bool isOn;
    int savedPointer;

public:
    History();

    bool Clear();
    bool Write(Command command);
    std::string ToString(int bottomBound);

    bool IsOn();
    void IsOn(bool set);

    int SavedPointer();
    void SavedPointer(int set);

    int Size();

};

#endif //LAB17_HISTORY_H
