/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/MecanumDriveSystem.h"

MecanumDriveSystem::MecanumDriveSystem() : Subsystem("ExampleSubsystem") {}

void MecanumDriveSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
	//fl = new WPI_TalonSRX(FRONT_LEFT_MOTOR_ID); // Front Left
	//rl = new WPI_TalonSRX(REAR_LEFT_MOTOR_ID); // Rear Left
	//fr = new WPI_TalonSRX(FRONT_RIGHT_MOTOR_ID); // Front Right
	//rr = new WPI_TalonSRX(REAR_RIGHT_MOTOR_ID); // Rear Right

	m_robotDrive = new frc::MecanumDrive(fl, rl, fr, rr);
	m_robotDrive->SetExpiration(0.5);
	m_robotDrive->SetSafetyEnabled(false);

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
