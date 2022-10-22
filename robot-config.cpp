#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FR = motor(PORT1, ratio18_1, true);
motor FL = motor(PORT2, ratio18_1, false);
motor BR = motor(PORT9, ratio18_1, true);
motor BL = motor(PORT10, ratio18_1, false);
motor Intake = motor(PORT11, ratio18_1, false);
led valve = led(Brain.ThreeWirePort.A);
led EndGame = led(Brain.ThreeWirePort.B);
motor Intake2 = motor(PORT12, ratio18_1, true);
motor Shooter = motor(PORT19, ratio6_1, true);
motor Shooter2 = motor(PORT20, ratio6_1, true);
pot PC = pot(Brain.ThreeWirePort.C);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}