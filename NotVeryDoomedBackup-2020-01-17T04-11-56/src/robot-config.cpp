#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Ramp = motor(PORT3, ratio36_1, false);
motor BackLeft = motor(PORT4, ratio18_1, false);
motor BackRight = motor(PORT5, ratio18_1, true);
controller Controller1 = controller(primary);
motor ClawLeft = motor(PORT6, ratio18_1, false);
motor ClawRight = motor(PORT7, ratio18_1, true);
motor Ramp2 = motor(PORT8, ratio36_1, true);
sonar RearRange = sonar(Brain.ThreeWirePort.A);
motor ArmLeft = motor(PORT9, ratio6_1, false);
motor ArmRight = motor(PORT10, ratio6_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}