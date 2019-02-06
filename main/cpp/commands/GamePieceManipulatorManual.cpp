/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "commands/GamePieceManipulatorManual.h"
#include "subsystems/GamePieceManipulator.h"

GamePieceManipulatorManual::GamePieceManipulatorManual(double v) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(gamePieceManipulator);
  velocity = v;
}

// Called just before this Command runs the first time
void GamePieceManipulatorManual::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void GamePieceManipulatorManual::Execute() {
  gamePieceManipulator->Move(velocity);
}

// Make this return true when this Command no longer needs to run execute()
bool GamePieceManipulatorManual::IsFinished() { return false; }

// Called once after isFinished returns true
void GamePieceManipulatorManual::End() {
  gamePieceManipulator->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GamePieceManipulatorManual::Interrupted() {}
