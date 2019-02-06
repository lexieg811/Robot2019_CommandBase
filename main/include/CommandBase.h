#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include <string>
#include <frc/Commands/Command.h>
#include <frc/WPILib.h>
#include "OI.h"
#include "subsystems/GamePieceManipulator.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public frc::Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	// static Climber *climber;
    static GamePieceManipulator *gamePieceManipulator;
	// static OI *oi;
};
#endif