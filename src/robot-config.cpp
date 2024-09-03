#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
rotation Rotation8 = rotation(PORT8, false);
motor R1 = motor(PORT1, ratio6_1, false);
motor R2 = motor(PORT2, ratio6_1, false);
motor R3 = motor(PORT3, ratio6_1, false);
motor L1 = motor(PORT4, ratio6_1, true);
motor L2 = motor(PORT5, ratio6_1, true);
motor L3 = motor(PORT6, ratio6_1, true);
inertial InertialSens = inertial(PORT12);
motor CHAIN = motor(PORT7, ratio6_1, false);
digital_out HOOK = digital_out(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);
distance Distance10 = distance(PORT10);

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