#include "CommandBase.h"
#include "frc/Commands/Scheduler.h"

// Initialize a single static pointer/instance of all of your subsystems to NULL
MecanumDriveSystem* CommandBase::mecanumDriveSystem = NULL;
GamePieceManipulator* CommandBase::gamePieceManipulator = NULL;
HABClimber* CommandBase::habClimber = NULL;
Utility* CommandBase::utility = NULL;

CommandBase::CommandBase(char const *name): frc::Command(name) {}

CommandBase::CommandBase(): frc::Command() {}

void CommandBase::init()
{
    mecanumDriveSystem = new MecanumDriveSystem();
    gamePieceManipulator = new GamePieceManipulator();
    habClimber = new HABClimber();
    utility = new Utility();
}
