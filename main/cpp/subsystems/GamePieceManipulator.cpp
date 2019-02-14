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
  hingePot = new frc::AnalogInput(0);
  hingePot->SetOversampleBits(4);
  int bits = hingePot->GetOversampleBits();
  hingePot->SetAverageBits(2);
  bits = hingePot->GetAverageBits();

}

void GamePieceManipulator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  }

// Put methods for controlling this subsystem
// here. Call these from Commands.
/*******************************
 * Pneumatic Hatch Panel Methods
********************************/

void GamePieceManipulator::HatchEject() {
    hatchPanel->Set(frc::DoubleSolenoid::Value::kForward);
  }

void GamePieceManipulator::HatchInject() {
    hatchPanel->Set(frc::DoubleSolenoid::Value::kReverse);
  }

/*******************************
    Arm Raise & Lower Methods
********************************/

void GamePieceManipulator::Move(double v) {

    double position = hingePot->GetVoltage();

    if (v > 0 && position > HINGE_MIN
        || v < 0 && position < HINGE_MAX) {
        hingeMotor->Set(v);
    }
    else {
        hingeMotor->Set(0.0);
    }
}
void GamePieceManipulator::Stop() {
    hingeMotor->Set(0.0);
}


double GamePieceManipulator::GetPosition() {
    return hingePot->GetVoltage();
}

/*******************************
    Cargo Ball Methods
********************************/
void GamePieceManipulator::CargoLoad() {
    ballMotor->Set(1.0);
}
void GamePieceManipulator::CargoEject() {
    ballMotor->Set(-1.0);
}
void GamePieceManipulator::CargoStop() {
    ballMotor->Set(0.0);
}
