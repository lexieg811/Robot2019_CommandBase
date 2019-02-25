/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Utility.h"

Utility::Utility() : Subsystem("Utility") {
  ballHatchLight = new frc::Relay(0);
  cameraIlluminator = new frc::Relay(1);
  cameraIlluminator->Set(frc::Relay::Value::kForward);
}

void Utility::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Utility::SignalLightOn() {
  ballHatchLight->Set(frc::Relay::Value::kOn);
  cameraIlluminator->Set(frc::Relay::Value::kOff);
}

void Utility::SignalLightOff() {
  ballHatchLight->Set(frc::Relay::Value::kOff);
  cameraIlluminator->Set(frc::Relay::Value::kForward);
}
void Utility::CameraCapture() {

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
