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
  ballMotor = new WPI_TalonSRX(1); // CAN ID
  // Hinge Raise/Lower Motor
  hingeMotorL = new WPI_TalonSRX(6); // CAN ID
  hingeMotorR = new WPI_TalonSRX(7); // CAN ID
  hingeMotorL->EnableCurrentLimit(true);
  hingeMotor->EnableCurrentLimit(true);
  hingePotL = new frc::AnalogInput(0);
  hingePotR = new frc::AnalogInput(1);
  hingePotL->SetOversampleBits(4);
  hingePotR->SetOversampleBits(4);
  int bitsL = hingePotL->GetOversampleBits();
  int bitsR = hingePotR->GetOversampleBits();
  hingePotL->SetAverageBits(2);
  hingePotR->SetAverageBits(2);
  bitsL = hingePotL->GetAverageBits();
  bitsR = hingePotR->GetAverageBits();

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
//v = velocity
#define GP_DEADBAND 0.5
void GamePieceManipulator::Move(double v) {

    double positionL = hingePotL->GetVoltage();

    if ((v > GP_DEADBAND && positionL > HINGE_MIN_LEFT)
        || (v < -GP_DEADBAND && positionL < HINGE_MAX_LEFT)) {
        v *= 10.0;
        hingeMotorL->Set(v);
    }
    else {
        hingeMotorL->Set(0.0);
    }

    double positionR = hingePotR->GetVoltage();

    if ((v > GP_DEADBAND && positionR > HINGE_MIN_RIGHT)
        || (v < -GP_DEADBAND && positionR < HINGE_MAX_RIGHT)) {
        v *= 10.0;
        hingeMotorR->Set(v*.91);
    }
    else {
        hingeMotorR->Set(0.0);
    }
    
}
void GamePieceManipulator::Stop() {
    hingeMotorL->Set(0.0);
    hingeMotorR->Set(0.0);
}


double GamePieceManipulator::GetLPosition() {
    return hingePotL->GetVoltage();
}
double GamePieceManipulator::GetRPosition() {
    return hingePotR->GetVoltage();
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
