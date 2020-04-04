//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#ifndef LAB17_LOG_H
#define LAB17_LOG_H

#include "History.h"

class Log
{
private:
    std::string path;                   //logfile path
    bool isAppend;                      //false - delete all old records from logfile when save new

public:
    Log();

    bool SaveHistory(History& history); //save history to logfile
    std::string GetFromLogfile();       //get old records from logfile

    std::string GetPath();              //getter for 'path'
    bool SetPath(const std::string&);          //setter for 'path'

    bool IsAppend();                    //getter for 'isAppend'
    void IsAppend(bool set);            //setter for 'isAppend'
};

#endif //LAB17_LOG_H
