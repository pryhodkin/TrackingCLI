#include <iostream>
#include "CLI.h"

int main()
{
    CLI* cli = new CLI();
    cli -> Greet();
    bool check;

    while(true)
    {
        Command* command = cli -> GetCommand();             //getting command from user
        check = cli -> ExecuteCommand(command);             //executing command
        if(!check)                                          //if execution was not successful aware user about it
            std::cout << "Something went wrong..." << '\n';
        if(!(command -> GetCommand()).empty())
            std::cout << '\n';
    }
    return 0;
}