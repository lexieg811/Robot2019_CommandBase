/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "CommandBase.h"

class HABLift : public CommandBase {
 public:
  HABLift();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};

//These: * & -> all have something to do with pointers but I don't understand pointers, why we use them, or how to use them
//so I'm really confused on how to transfer things from the Protobot to the real Robot
//Other Things I'm Confused About: 
//    -what do I put in the HABClimber.cpp subsystem? 
//    -how do I organise everything in the HABLift.cpp command?
//    -how do all the HAB commands fit together?