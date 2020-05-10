# TrackingCLI
Base CLI to save commands in history and log

## How to add custom command?
1. Add private method to CLI class that would be executed with this command.
2. Add ```if``` _condition_ to public method ```CLI::execute()```.
3. Add a description of your command to ```StringConsts::Help```.

You need to edit 3 files: **CLI.h**, **CLI.cpp**, **StringConsts.cpp**.

example:

**CLI.h**
```c++  class: lineNo
...

class CLI
{
private:
    ...
    
public:
    CLI();
    
    Command* GetCommand();
    bool ExecuteCommand(); //this method you need to edit
    ...
    
private:
    bool help();
    bool quit();
    ...
    bool customCommand();  //your method
    
    bool fileExists(const std::string& path)
};
```

**CLI.cpp**
```c++
...

CLI::CLI()
{
    ...
}

Command* CLI::GetCommand()
{
    ...
}

bool CLI::ExecuteCommand(Command *command)
{
    std::string func = command -> GetCommand();
    if(func.empty()) return true; 
    std::vector<std::string> args = command -> GetArguments();
    if(history -> IsOn()) history -> Write(*command);
    if(func == "help")            return help();
    if(func == "quit")            return quit();
    ...
    // add this condition
    if(func == "customCommand")   return customCommand(); 
    // instead of "customCommand"
    // place name of your command.
    // name must not contain any spaces.
    return false;
}

...

bool CLI::customCommand() // implement your method
{
    // some actions that should be effected
    // method must return an indication of successful execution 
    // (true if ok,
    // otherwise false)
}

```

**StringConsts.cpp**
```c++

std::string StringConsts::Help =  "This program is doing nothing:\n"
                                  "\n"
                                  "Available commands:\n"
                                  "\n"
                                  "\n"
                                  "-\t help              -\t this instructions\n"
                                  "-\t quit              -\t save history to logfile and exit from program\n"
                                  ...
                                  //add a description to actions that perform your command
                                  //like this
                                  "-\t costomCommand"    -\t description\n";
                                  
```

