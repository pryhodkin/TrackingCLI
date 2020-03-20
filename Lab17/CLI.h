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
    Log* log;
    History* history;

public:
    CLI();

    Command* GetCommand();
    bool ExecuteCommand(Command* command);
    void Greet();
    void Prompt();

private:
    bool help();
    bool quit();
    bool exit();
    bool save();
    bool load();
    bool logfile();
    bool logfile(std::string newpath);
    bool list();
    bool logOn();
    bool logOff();
    bool logAppend();
    bool logNew();
    bool logClearHistory();

    bool fileExists(std::string path);
};

#endif //LAB17_CLI_H
