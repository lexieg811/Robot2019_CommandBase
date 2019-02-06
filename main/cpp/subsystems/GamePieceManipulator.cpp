/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/GamePieceManipulator.h"

GamePieceManipulator::GamePieceManipulator() : frc::Subsystem("GamePieceManipulator") {

  // Pneumatic Hatch Panel Eject
  hatchPanel = new frc::DoubleSolenoid(0,1); // PCM Ports
  // Cargo Ball Intake/Eject Motor
  ballMotor = new WPI_TalonSRX(6); // CAN ID
  // Hinge Raise/Lower Motor
  hingeMotor = new WPI_TalonSRX(7); // CAN ID

}

void GamePieceManipulator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  }

// Put methods for controlling this subsystem
// here. Call these from Commands.

void GamePieceManipulator::Eject() {
    hatchPanel->Set(frc::DoubleSolenoid::Value::kForward);
  }

void GamePieceManipulator::Inject() {
    hatchPanel->Set(frc::DoubleSolenoid::Value::kReverse);
  }
