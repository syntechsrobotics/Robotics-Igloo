using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Ramp;
extern motor BackLeft;
extern motor BackRight;
extern controller Controller1;
extern motor ClawLeft;
extern motor ClawRight;
extern motor Ramp2;
extern sonar RearRange;
extern motor ArmLeft;
extern motor ArmRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );