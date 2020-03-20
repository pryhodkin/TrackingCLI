//
// Created by Yaroslav Pryhodko on 19.03.2020.
//

#include "StringConsts.h"

std::string StringConsts::Prompt = "$";
std::string StringConsts::Help =  "This program is doing nothing:\n"
                                  "\n"
                                  "Available commands:\n"
                                  "\n"
                                  "\n"
                                  "-\t help              -\t this instructions\n"
                                  "-\t quit              -\t save history to logfile and exit from program\n"
                                  "-\t exit              -\t exit from program\n"
                                  "-\t save              -\t save history to logfile\n"
                                  "-\t load              -\t display logfile content\n"
                                  "-\t logfile           -\t with 1 parameter sets this parameter as logfile\n"
                                  " \t                   -\t without parameter displays logfile path\n"
                                  "-\t list              -\t displays history\n"
                                  "-\t log on            -\t turns on writing to history\n"
                                  "-\t log off           -\t turns off writing to history\n"
                                  "-\t log append        -\t saving to logfile appending\n"
                                  "-\t log new           -\t saving to logfile deleting all from file\n"
                                  "-\t log clear history -\t clear current history\n";

std::string StringConsts::Greet = "Greetings!\n";