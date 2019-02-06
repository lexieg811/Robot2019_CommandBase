#include "CommandBase.h"
#include "frc/Commands/Scheduler.h"

// Initialize a single static pointer/instance of all of your subsystems to NULL
//Climber* CommandBase::climber = NULL;
// OI* CommandBase::oi = NULL;
GamePieceManipulator* CommandBase::gamePieceManipulator = NULL;

CommandBase::CommandBase(char const *name): frc::Command(name) {}

CommandBase::CommandBase(): frc::Command() {}

void CommandBase::init()
{
//	climber = new Climber();
//	oi = new OI();
    gamePieceManipulator = new GamePieceManipulator();
}
