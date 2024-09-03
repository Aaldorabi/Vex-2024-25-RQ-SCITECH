using namespace vex;

extern brain Brain;

// VEXcode devices
extern rotation Rotation8;
extern motor R1;
extern motor R2;
extern motor R3;
extern motor L1;
extern motor L2;
extern motor L3;
extern inertial InertialSens;
extern motor CHAIN;
extern digital_out HOOK;
extern controller Controller1;
extern distance Distance10;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );