//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#include <iostream>
#include <fstream>
#include "CLI.h"

CLI::CLI()
{
    log = new Log();
    history = new History();
}

Command* CLI::GetCommand()
{
    Prompt();
    std::string line;
    getline(std::cin, line);
    return new Command(line);
}

bool CLI::ExecuteCommand(Command *command)
{
    std::string func = command -> GetCommand();
    if(func.empty()) return true;
    std::vector<std::string> args = command -> GetArguments();
    if(history -> IsOn()) history -> Write(*command);
    if(func == "help")                        return help();
    if(func == "quit")                        return quit();
    if(func == "exit")                        return exit();
    if(func == "save")                        return save();
    if(func == "load")                        return load();
    if(func == "logfile" && args.empty())     return logfile();
    if(func == "logfile" && args.size() == 1) return logfile(args[0]);
    if(func == "list")                        return list();
    if(func == "log" && args.size() == 1)
    {
        if(args[0] == "on")                   return logOn();
        if(args[0] == "off")                  return logOff();
        if(args[0] == "append")               return logAppend();
        if(args[0] == "new")                  return logNew();
    }
    if(func == "log" && args.size() == 2)
        if(args[0] == "clear" && args[1] == "history")
                                              return logClearHistory();
    return false;
}

void CLI::Greet()
{
    std::cout << "Logfile path: " << log -> GetPath() << '\n';
    std::cout << StringConsts::Greet << "\n\n";
    std::cout << StringConsts::Help  << '\n';
}

void CLI::Prompt()
{
    std::cout << StringConsts::Prompt;
}


bool CLI::help()
{
    std::cout << StringConsts::Help << '\n';
    return true;
}

bool CLI::quit()
{
    bool saveCheck = save();
    bool exitCheck = exit();
    return (saveCheck && exitCheck);
}

bool CLI::exit()
{
    std::exit(0);
    return true;
}

bool CLI::save()
{
    bool check = log -> SaveHistory(*history);
    if(check)
        history -> SavedPointer(history -> Size());
    std::cout << "History saved" << '\n';
    return check;
}

bool CLI::load()
{
    std::cout << "Logfile:" << "\n\n";
    std::cout << log -> GetFromLogfile() << '\n';
    return true;
}

bool CLI::logfile()
{
    std::cout << "Logfile path: " << log -> GetPath() << '\n';
    return true;
}

bool CLI::logfile(std::string newpath)
{
    if(log -> SetPath(newpath))
        std::cout << "Logfile path setted as: " << newpath << '\n';
    else
    {
        std::cout << "Invalid path, please try again." << '\n';
        return false;
    }

    if(fileExists(newpath))
        std::cout << "This is the file that already exists..." << '\n';
    else
        std::cout << "This file was just created" << '\n';

    return true;
}

bool CLI::list()
{
    std::cout << "Current History:" << "\n\n";
    std::cout << history -> ToString(0) << "\n\n";
    return true;
}

bool CLI::logOn()
{
    history -> IsOn(true);
    std::cout << "Writing to history switched on." << '\n';
    return true;
}

bool CLI::logOff()
{
    history -> IsOn(false);
    std::cout << "Writing to history switched off." << '\n';
    return true;
}

bool CLI::logAppend()
{
    log -> IsAppend(true);
    std::cout << "When you save the history, it saves to logfile appending to elder records." << '\n';
    return true;
}

bool CLI::logNew()
{
    log -> IsAppend(false);
    std::cout << "When you save the history, it saves to logfile replacing elder records." << '\n';
    return true;
}

bool CLI::logClearHistory()
{
    bool check = history -> Clear();
    std::cout << "History cleared" << '\n';
    return check;
}


bool CLI::fileExists(std::string path)
{
    std::fstream check(path, std::fstream::in);
    return (bool)check;
}