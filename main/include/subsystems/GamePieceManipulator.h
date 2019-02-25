/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/PIDController.h>
#include <frc/PIDSource.h>
#include <frc/PIDOutput.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <frc/AnalogInput.h>
#include <frc/DigitalInput.h>

// Forward declarations
class HingePIDSource;
class HingePIDOutput;

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

  HingePIDSource *hingeInL;
  HingePIDSource *hingeInR;
  HingePIDOutput *hingeOutL;
  HingePIDOutput *hingeOutR;
  frc::PIDController *hingePIDL;
  frc::PIDController *hingePIDR;
  frc::DigitalInput *ballIntakeLimit;

 public:
  GamePieceManipulator();
  void InitDefaultCommand() override;
  void HatchEject();
  void HatchInject();
  void Move(double); // manual arm raise/lower
  void MoveTo(double); // move to position arm raise/lower
  void EnablePIDLoop();
  void DisablePIDLoop();
  void Stop();
  double GetLPosition();
  double GetRPosition();
  void CargoLoad();
  void CargoEject();
  void CargoStop();
};

// Helpers for hinge PIDController -------------------------------------------

class HingePIDSource : public frc::PIDSource {
  frc::AnalogInput *m_pot;
  double m_min;
  double m_range;
 public:
  HingePIDSource(frc::AnalogInput *pot, double min, double range);
  double PIDGet();
  void SetPIDSourceType(frc::PIDSourceType pidSource);
};

class HingePIDOutput : public frc::PIDOutput {
  WPI_TalonSRX *m_motor;
  frc::AnalogInput *m_pot;
  double m_min;
  double m_range;
 public:
  HingePIDOutput(WPI_TalonSRX *motor, frc::AnalogInput *pot,
    double min, double range);
  void PIDWrite(double d);
};
