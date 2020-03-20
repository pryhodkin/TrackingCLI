#include <iostream>
#include "CLI.h"

int main()
{
    CLI* cli = new CLI();
    cli -> Greet();
    bool check;

    do
    {
        Command* command = cli -> GetCommand();
        check = cli -> ExecuteCommand(command);
        if(!check)
            std::cout << "Something went wrong..." << '\n';
        if(!(command -> GetCommand()).empty())
        std::cout << '\n';
    }
    while(true);

    return 0;
}