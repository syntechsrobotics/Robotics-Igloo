/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         11              
// Arm                  motor         3               
// BackLeft             motor         4               
// BackRight            motor         5               
// Controller1          controller                    
// ClawLeft             motor         6               
// ClawRight            motor         7               
// Arm2                 motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) { //
  // Initializing Robot Configuration. DO NOT REMOVE!             //
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

//FrontLeft.spinFor(-1.8, vex::rotationUnits::rev, false);
 // FrontRight.spinFor(-1.8, vex::rotationUnits::rev, false);
//  BackRight.spinFor(-1.8, vex::rotationUnits::rev, false);
 // BackLeft.spinFor(-1.8, vex::rotationUnits::rev, true);

  //ClawLeft.spin(vex::directionType::fwd, 95,vex::velocityUnits::pct);
  //ClawRight.spin(vex::directionType::fwd, 95,vex::velocityUnits::pct);

//  FrontLeft.spinFor(1.8, vex::rotationUnits::rev, false);
//  FrontRight.spinFor(1.8, vex::rotationUnits::rev, false);
//  BackRight.spinFor(1.8, vex::rotationUnits::rev, false);
//  BackLeft.spinFor(1.8, vex::rotationUnits::rev, true);
// ClawLeft.stop();
//  ClawRight.stop(); 

//Attempt to get > 1 point auto

FrontLeft.spinFor(2, vex::rotationUnits::rev, false);
FrontRight.spinFor(2, vex::rotationUnits::rev, false);
BackRight.spinFor(2, vex::rotationUnits::rev, false);
BackLeft.spinFor(2, vex::rotationUnits::rev, true);

ClawLeft.spin(vex::directionType::fwd, 95,vex::velocityUnits::pct);
ClawRight.spin(vex::directionType::fwd, 95,vex::velocityUnits::pct);

}

// we're doomed

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
 //Function for ClawSpeed

 int ClawSpeed = 85;
  int ArmSpeed = 45;
  int ClawOutSpeed = 90;
  int ClawDifference = 0;
  bool DriveSlow = false;

  void ClawSpeedDown (void){

    ClawDifference = 5;
      ClawSpeed = ClawSpeed - ClawDifference;
      ClawDifference = 0;
      if (ClawSpeed < 0) {
        ClawSpeed = ClawSpeed +5;
      }
      Controller1.Screen.clearLine();
      Controller1.Screen.print(ClawSpeed);

  }

  void ClawSpeedUp (void){

      ClawDifference = 5;
      ClawSpeed = ClawSpeed + ClawDifference;
      ClawDifference = 0;
      if (ClawSpeed > 100) {
        ClawSpeed = ClawSpeed - 5;
      }
       Controller1.Screen.clearLine();
    Controller1.Screen.print(ClawSpeed);
  }

  void ClawReset (void){
    ClawDifference = 0;
    ClawSpeed = 70;
    Controller1.Screen.clearLine();
    Controller1.Screen.print("Output speed reset");
  }
    
   

void usercontrol(void) {
  // User control code here, inside the loop 

 


  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // Drive code here pls
    // ........................................................................

    

    if (Controller1.ButtonX.pressing()){
      DriveSlow = false;
      Controller1.Screen.clearLine();
      Controller1.Screen.print("NORMAL speed");

    }
      
      
      else if (Controller1.ButtonB.pressing()){

      DriveSlow = true;
      Controller1.Screen.clearLine();
      Controller1.Screen.print("SLOW speed");

    }

    // This is the left part of Tank Drive 

    if (DriveSlow == false){
      FrontLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(),
                    vex::velocityUnits::pct);
      BackLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(),
                   vex::velocityUnits::pct); //(Axis3+Axis4)/2
    } 
      else if (DriveSlow == true){
       FrontLeft.spin(vex::directionType::fwd, Controller1.Axis3.value()/10,
                    vex::velocityUnits::pct);
       BackLeft.spin(vex::directionType::fwd, Controller1.Axis3.value()/10,
                     vex::velocityUnits::pct);
    }
    else {
      FrontRight.stop(brakeType::hold);
      BackRight.stop(brakeType::hold);
    }

    // This is the right part of the Tank Drive 

    if (DriveSlow == false){
    FrontRight.spin(vex::directionType::fwd, Controller1.Axis2.value(),
                    vex::velocityUnits::pct);
    BackRight.spin(vex::directionType::fwd, Controller1.Axis2.value(),
                   vex::velocityUnits::pct);
    }
      else if (DriveSlow == true){
     FrontRight.spin(vex::directionType::fwd, Controller1.Axis2.value()/10,
                    vex::velocityUnits::pct);
     BackRight.spin(vex::directionType::fwd, Controller1.Axis2.value()/10,
                   vex::velocityUnits::pct);
    } 
    else {
      FrontRight.stop(brakeType::hold);
      BackRight.stop(brakeType::hold);
    } 

    // Arm

    if (Controller1.ButtonR1.pressing()) {
      Arm.spin(vex::directionType::fwd, ArmSpeed, vex::velocityUnits::pct);
      Arm2.spin(vex::directionType::fwd, ArmSpeed, vex::velocityUnits::pct);
    } else if (Controller1.ButtonR2.pressing()) {
      Arm.spin(vex::directionType::rev, ArmSpeed, vex::velocityUnits::pct);
      Arm2.spin(vex::directionType::rev, ArmSpeed, vex::velocityUnits::pct);
    } else {
        Arm.stop();
        Arm2.stop();
    }
    // Claw
                                                      
    if (Controller1.ButtonL1.pressing())  {
      ClawLeft.spin(vex::directionType::fwd, ClawSpeed,
                    vex::velocityUnits::pct);
      ClawRight.spin(vex::directionType::fwd, ClawSpeed,
                     vex::velocityUnits::pct);
    } else if (Controller1.ButtonL2.pressing()) {
      ClawLeft.spin(vex::directionType::rev, ClawOutSpeed,
                    vex::velocityUnits::pct);
      ClawRight.spin(vex::directionType::rev, ClawOutSpeed,
                     vex::velocityUnits::pct);
    } else {
      ClawLeft.stop();
      ClawRight.stop();
    }

    // Adjust Claw Speed

     (Controller1.ButtonDown.pressed(ClawSpeedDown));
     (Controller1.ButtonUp.pressed(ClawSpeedUp)); 
     (Controller1.ButtonRight.pressed(ClawReset));

    
 

  
  


wait(20, msec); // Sleep the task for a short amount of time to
                // prevent wasted resources.
}

}
//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
