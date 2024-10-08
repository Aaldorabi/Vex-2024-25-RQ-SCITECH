using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor R1;
extern motor R2;
extern motor R3;
extern motor L1;
extern motor L2;
extern motor L3;
extern inertial InertialSens;
extern digital_out HOOK;
extern controller Controller1;
extern rotation ForwardTracker;
extern rotation SidewayTracker;
extern motor ChainIntake;
extern motor WheelIntake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );