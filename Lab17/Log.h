//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#ifndef LAB17_LOG_H
#define LAB17_LOG_H

#include "History.h"

class Log
{
private:
    std::string path;
    bool isAppend;

public:
    Log();

    bool SaveHistory(History& history);
    std::string GetFromLogfile();

    std::string GetPath();
    bool SetPath(std::string);

    bool IsAppend();
    void IsAppend(bool set);
};

#endif //LAB17_LOG_H
