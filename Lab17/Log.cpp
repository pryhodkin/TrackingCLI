//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#include <fstream>
#include <iterator>
#include "Log.h"

Log::Log()
{
    isAppend = true;
    path = "d:/log.txt";
}

bool Log::SaveHistory(History& history)
{
    std::fstream logfile;

    if(isAppend)
        logfile.open(path, std::fstream::app);
    else
        logfile.open(path, std::fstream::out);

    logfile << history.ToString(history.SavedPointer());
    logfile.close();
    return (bool)logfile;
}

std::string Log::GetFromLogfile()
{
    //Made with principle "Working? Don't touch!1!"
    std::string result;
    std::fstream logfile(path, std::fstream::in);
    logfile >> std::noskipws;
    std::copy(std::istream_iterator<char>(logfile), std::istream_iterator<char>(), std::back_inserter(result));
    logfile.close();
    return result;
}


std::string Log::GetPath()
{
    return path;
}

bool Log::SetPath(std::string newpath)
{
    std::fstream checkPath(newpath, std::fstream::in);
    if(!checkPath)
    {
        return false;
    }
    path = newpath;
    return true;
}

bool Log::IsAppend()
{
    return isAppend;
}

void Log::IsAppend(bool set)
{
    isAppend = set;
}
