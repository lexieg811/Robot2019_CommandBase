/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HABLift.h"
#include "subsystems/HABClimber.h"
#include "OI.h"

#define DEADBAND .15

HABLift::HABLift() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(habClimber);
}

// Called just before this Command runs the first time
void HABLift::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HABLift::Execute() {
  if (-oi->m_XboxCoDriver->GetRawAxis(1) > DEADBAND) {
    habClimber->LiftFront();
  }
  else if (oi->m_XboxCoDriver->GetRawAxis(1) < -DEADBAND) {
    habClimber->LowerFront();
  }
  else {
     habClimber->StopFront();
  }
  if (-oi->m_XboxCoDriver->GetRawAxis(5) > DEADBAND) {
    habClimber->LiftRear();
  }
  else if (oi->m_XboxCoDriver->GetRawAxis(5) < -DEADBAND) {
    habClimber->LowerRear();
  }
  else {
    habClimber->StopRear();
  }
}

// Make this return true when this Command no longer needs to run execute()
bool HABLift::IsFinished() { return false; }

// Called once after isFinished returns true
void HABLift::End() {
  habClimber->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HABLift::Interrupted() {
  habClimber->Stop();
}
