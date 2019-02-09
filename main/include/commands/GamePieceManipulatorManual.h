/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "CommandBase.h"

#define HINGE_RAISE_INPUT_AXIS 2  // Left Trigger
#define HINGE_LOWER_INPUT_AXIS 3  // Right Trigger

class GamePieceManipulatorManual : public CommandBase {
 public:
  GamePieceManipulatorManual();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
