# Robot2019_CommandBase
FRC 2019 Command-Based Robot Deep Space
## Code Refactoring:
  * ~~Drive Deadband~~
  * ~~Square Inputs to drive~~
  * Climber controls/functionality
  * Cargo Ball control/functionality
  * ~~Signal light control/functionality~~
  * ~~Add navX for gyro control~~
  * Hinge/arm manual control
  * Hinge/arm position control (software stops)
  * ~~Camera functionality and control~~
  * Test/Fix code version string (env.h)

## SubSystems
  * MecanumDriveSystem
  * GamePieceManipulator
  * HABClimber
  * Utility (Signal Light)

## Commands
 * CargoBallEject
 * CargoBallIntake
 * GamePieceManipulatorManual
 * GamePieceManipulatorMoveToPosition
 * HABForward
 * HABLift
 * HABRetractFront
 * HABRetractRear
 * HABReverse
 * HatchPanelEject
 * MecanumDriveCommand

## OI
 * XBoxController
