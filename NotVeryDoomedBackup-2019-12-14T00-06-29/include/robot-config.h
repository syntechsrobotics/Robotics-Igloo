using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontLeft;
extern motor FrontRight;
extern motor Arm;
extern motor BackLeft;
extern motor BackRight;
extern controller Controller1;
extern motor ClawLeft;
extern motor ClawRight;
extern motor Arm2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );