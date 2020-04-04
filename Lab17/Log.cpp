//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#include <fstream>
#include <iterator>
#include "Log.h"

Log::Log()
{
    isAppend = true;                                    //default value is true
    path = "d:/log.txt";                                //default path
}

bool Log::SaveHistory(History& history)
{
    std::fstream logfile;

    if(isAppend)                                        //if we use append, open file for appending
        logfile.open(path, std::fstream::app);
    else                                                //else for overwrite
        logfile.open(path, std::fstream::out);

    logfile << history.ToString(history.SavedPointer());//sets savedPointer on current end of history
    logfile.close();
    if(logfile)
        history.SavedPointer(history.Size());
    return (bool)logfile;                               //returns property of success
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

bool Log::SetPath(const std::string& newpath)
{
    std::fstream checkPath(newpath, std::fstream::in);  //validation of newpath
    if(!checkPath)
        return false;
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
