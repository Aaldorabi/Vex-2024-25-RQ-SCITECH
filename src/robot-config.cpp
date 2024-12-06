#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor R1 = motor(PORT1, ratio6_1, false);
motor R2 = motor(PORT10, ratio18_1, false);
motor R3 = motor(PORT3, ratio6_1, false);
motor L1 = motor(PORT4, ratio6_1, true);
motor L2 = motor(PORT5, ratio6_1, true);
motor L3 = motor(PORT6, ratio6_1, true);
inertial InertialSens = inertial(PORT12);
digital_out MogoMech = digital_out(Brain.ThreeWirePort.B);
controller Controller1 = controller(primary);
rotation SidewayTracker = rotation(PORT8, false);
digital_out ARMPiston = digital_out(Brain.ThreeWirePort.A);
digital_out NeutralPiston = digital_out(Brain.ThreeWirePort.C);
motor IntakeMotorA = motor(PORT9, ratio18_1, true);
motor IntakeMotorB = motor(PORT7, ratio18_1, false);
motor_group Intake = motor_group(IntakeMotorA, IntakeMotorB);
rotation ForwardTracker = rotation(PORT11, false);

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