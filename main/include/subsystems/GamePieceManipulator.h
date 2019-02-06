/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>

class GamePieceManipulator : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  // Pneumatic Hatch Panel Eject
  frc::DoubleSolenoid *hatchPanel;

  // Cargo Ball Intake/Eject Motor
  WPI_TalonSRX *ballMotor;

  // Hinge Raise/Lower Motor
  WPI_TalonSRX *hingeMotor;

 public:
  GamePieceManipulator();
  void InitDefaultCommand() override;
  void Eject();
  void Inject();
};
