//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#ifndef LAB17_LOG_H
#define LAB17_LOG_H

#include "History.h"

class Log
{
public:
    Log();

    bool SaveHistory(History& history);       //save history to logfile
    std::string GetFromLogfile() const;       //get old records from logfile

    std::string Path() const;                 //getter for 'path'
    bool Path(const std::string&);            //setter for 'path'

    bool IsAppend() const;                    //getter for 'isAppend'
    void IsAppend(bool set);                  //setter for 'isAppend'

private:
    std::string path;                   //logfile path
    bool isAppend;                      //false - delete all old records from logfile when save new

};

#endif //LAB17_LOG_H
