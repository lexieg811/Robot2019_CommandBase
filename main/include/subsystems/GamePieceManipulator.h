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
#include <frc/AnalogInput.h>

// Max and min voltage for hinge pot positions
#define HINGE_MAX_LEFT 4.7
#define HINGE_MIN_LEFT .9
#define HINGE_MAX_RIGHT 4.7 
#define HINGE_MIN_RIGHT .9
// Top: 4.7V Bottom: 1.2V (3.5V = 90 degrees)
// Appox .039V per degree *** NON-LINEAR ***

class GamePieceManipulator : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  // Pneumatic Hatch Panel Eject
  frc::DoubleSolenoid *hatchPanel;

  // Cargo Ball Intake/Eject Motor
  WPI_TalonSRX *ballMotor;

  // Hinge Raise/Lower Motor
  WPI_TalonSRX *hingeMotorL;
  WPI_TalonSRX *hingeMotorR;
  frc::AnalogInput *hingePotL;
  frc::AnalogInput *hingePotR;

 public:
  GamePieceManipulator();
  void InitDefaultCommand() override;
  void HatchEject();
  void HatchInject();
  void Move(double); // manual arm raise/lower
  void Stop();
  double GetLPosition();
  double GetRPosition();
  void CargoLoad();
  void CargoEject();
  void CargoStop();
};
