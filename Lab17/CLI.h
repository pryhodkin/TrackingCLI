//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#ifndef LAB17_CLI_H
#define LAB17_CLI_H

#include "Log.h"
#include "StringConsts.h"

class CLI
{
private:
    Log* log;                               //log to save current & get old history
    History* history;                       //history to save typed commands

public:
    CLI();

    Command* GetCommand() const;            //gets new command from console
    bool ExecuteCommand(Command* command);  //execute specific command
    void Greet()  const;                    //starting string
    void Prompt() const;                    //prompt to make user know that he can type some command

private:
    bool help();                             //help string with instructions how to use this CLI
    bool quit();                             //saves history & exits from CLI
    bool exit();                             //exits from CLI
    bool save();                             //saves history
    bool load();                             //displays records from logfile
    bool logfile();                          //displays current path of logfile
    bool logfile(const std::string& newpath);//sets logfile path
    bool list();                             //displays current history
    bool logOn();                            //switch on writing to history
    bool logOff();                           //switch off writing to history
    bool logAppend();                        //log.logAppend = true
    bool logNew();                           //log.logAppend = false
    bool logClearHistory();                  //clear current history

    bool fileExists(const std::string& path);      //check existing of specific file
};

#endif //LAB17_CLI_H
