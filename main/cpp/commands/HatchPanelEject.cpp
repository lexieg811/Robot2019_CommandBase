/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "commands/HatchPanelEject.h"
#include "subsystems/GamePieceManipulator.h"

HatchPanelEject::HatchPanelEject() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(gamePieceManipulator);
}

// Called just before this Command runs the first time
void HatchPanelEject::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HatchPanelEject::Execute() {
    gamePieceManipulator->HatchEject();
}

// Make this return true when this Command no longer needs to run execute()
bool HatchPanelEject::IsFinished() { return false; }

// Called once after isFinished returns true
void HatchPanelEject::End() {
    gamePieceManipulator->HatchInject();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HatchPanelEject::Interrupted() {
    gamePieceManipulator->HatchInject();
}
