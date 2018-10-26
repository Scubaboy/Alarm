#ifndef SystemCommands_H
#define SystemCommands_H

// System commands.
enum class Mode
{
    //Instructs system to enter passive mode.
    EnterPassive, 
    
    //Instructs system to enter active mode.
    EnterActive,

    //No system command received.
    NoCommand
};

enum class Action
{
    //Instructs system to take image.
    TakeImage,
    
    NoAction
};


#endif