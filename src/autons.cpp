#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

 

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(12, .8, 0, 1, 5); //12, 0.8, 0.005, 0.85, 5
  chassis.set_heading_constants(6, .2, 0, 1.2, 10);
  chassis.set_turn_constants(12, 0.2, 0.005, 1, 10); //12, 0.2, 0.002, 0.85, 15
  chassis.set_swing_constants(12,0.175,0.001,0.75,15); //  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_to_point(-12, 48,0,6,12);

}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void First_Auton(){
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(-90);
  chassis.turn_to_angle(45);
  chassis.turn_to_angle(-45);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */
void Right_Red_Stake(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(-72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,-72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);

  //chassis.drive_distance(4,-45,12,6,1,200,2000);
  chassis.drive_stop(brake);
  Intake.stop();
}



void Right_Red_Alliance_Stake_1(){

  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(-72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,-72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,-55,12,12,1,0,2500); //-14
  chassis.drive_distance(-27,-55,6,12,1,100,1500); //3 volts //-25in
  //chassis.drive_distance(-18,50,6,12,1,150,1500);
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(180,12,2,50,2000);
  chassis.drive_distance(19.5,180,12,12,1,300,2500);
  

  chassis.drive_distance(-12,180,12,6,2,0,2000);
  MogoMech.set(false);
  Intake.spin(reverse,12,volt);
  chassis.drive_distance(-35,45,12,6,2,0,2000);
  Intake.stop();
  chassis.drive_distance(13,45,12,6,1,300,2000);

  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);

  chassis.drive_stop(brake);
  Intake.stop();

}

void Left_Red_Stake(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,55,12,12,1,0,2500); //-14
}

void Left_Red_Alliance_Stake_1(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,55,12,12,1,0,2500); //-14
  chassis.drive_distance(-27,55,6,12,1,100,1500); //3 volts //-25in
  //chassis.drive_distance(-18,50,6,12,1,150,1500);
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(180,12,2,50,2000);
  chassis.drive_distance(19.5,180,12,12,1,300,2500);//

  

  chassis.drive_distance(-12,180,12,6,2,0,2000);
  MogoMech.set(false);
  Intake.spin(reverse,12,volt);
  chassis.drive_distance(-35,-45,12,6,2,0,2000);
  Intake.stop();
  chassis.drive_distance(13,-45,12,6,1,300,2000);

  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);

  //chassis.drive_distance(4,-45,12,6,1,200,2000);
  chassis.drive_stop(brake);
  Intake.stop();
}

void Left_Red_Alliance_Stake_2(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,55,12,12,1,0,2500); //-14
  chassis.drive_distance(-27,55,6,12,1,100,1500); //3 volts //-25in
  //chassis.drive_distance(-18,50,6,12,1,150,1500);
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(180,12,2,50,2000);
  chassis.drive_distance(19.5,180,12,12,1,300,2500);//

  //Intake alliance line donut
  chassis.turn_to_angle(-90,6,1,25,1500);
  Intake.spin(reverse,12,volt);
  wait(250, msec);
  Intake.spin(fwd,12,volt);
  chassis.drive_distance(12,-90,6,6,1,999,1500); 

  chassis.drive_distance(-12,-90,12,6,1,0,2500);//-8
  
  chassis.drive_distance(-12,180,12,6,2,0,2000);
  MogoMech.set(false);
  Intake.spin(reverse,12,volt);
  chassis.drive_distance(-35,-45,12,6,2,0,2000);
  Intake.stop();
  chassis.drive_distance(13,-45,12,6,1,300,2000);

  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);

  //chassis.drive_distance(4,-45,12,6,1,200,2000);
  chassis.drive_stop(brake);
  Intake.stop();
}

void Left_Red_Alliance_Stake_3(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,55,12,12,1,0,2500); //-14
  chassis.drive_distance(-27,55,6,12,1,100,1500); //3 volts //-25in
  //chassis.drive_distance(-18,50,6,12,1,150,1500);
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(180,12,2,50,2000);
  chassis.drive_distance(19.5,180,12,12,1,300,2500);//

  //Intake alliance line donut
  chassis.turn_to_angle(-90,6,1,25,1500);
  Intake.spin(reverse,12,volt);
  wait(250, msec);
  Intake.spin(fwd,12,volt);
  chassis.drive_distance(12,-90,6,6,1,999,1500); 



  chassis.drive_distance(-4,-45,12,6,1,0,1500);//-4
  chassis.drive_distance(-6,-45,12,6,1,0,2000);
  chassis.drive_distance(-6,-90,12,6,1,0,2500);//-8
  Intake.spin(reverse,12,volt);
  wait(250, msec);
  Intake.spin(fwd,12,volt);
  chassis.drive_distance(12,-90,6,6,0.5,200,1500);//we are splitting this into two parts, so that it can outtake midway //11in
  

  chassis.drive_distance(-12,180,12,6,2,0,2000);
  MogoMech.set(false);
  Intake.spin(reverse,12,volt);
  chassis.drive_distance(-35,-45,12,6,2,0,2000);
  Intake.stop();
  chassis.drive_distance(13,-45,12,6,1,300,2000);

  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);

  //chassis.drive_distance(4,-45,12,6,1,200,2000);
  chassis.drive_stop(brake);
  Intake.stop();
}

void Right_Blue_Stake(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(-72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,-72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,-55,12,12,1,0,2500); //-14
}

void Right_Blue_Stake_1(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(-72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,-72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,-55,12,12,1,0,2500); //-14
  chassis.drive_distance(-27,-55,6,12,1,100,1500); //3 volts //-25in
  //chassis.drive_distance(-18,50,6,12,1,150,1500);
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(180,12,2,50,2000);
  chassis.drive_distance(19.5,180,12,12,1,300,2500);//

  

  chassis.drive_distance(-12,180,12,6,2,0,2000);
  MogoMech.set(false);
  Intake.spin(reverse,12,volt);
  chassis.drive_distance(-35,45,12,6,2,0,2000);
  Intake.stop();
  chassis.drive_distance(13,45,12,6,1,300,2000);

  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);

  //chassis.drive_distance(4,-45,12,6,1,200,2000);
  chassis.drive_stop(brake);
  Intake.stop();
}

void Right_Blue_Stake_2(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(-72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,-72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,-55,12,12,1,0,2500); //-14
  chassis.drive_distance(-27,-55,6,12,1,100,1500); //3 volts //-25in
  //chassis.drive_distance(-18,50,6,12,1,150,1500);
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(180,12,2,50,2000);
  chassis.drive_distance(19.5,180,12,12,1,300,2500);//

  //Intake alliance line donut
  chassis.turn_to_angle(90,6,1,25,1500);
  Intake.spin(reverse,12,volt);
  wait(250, msec);
  Intake.spin(fwd,12,volt);
  chassis.drive_distance(12,90,6,6,1,999,1500); 

  chassis.drive_distance(-12,90,12,6,1,0,2500);//-8
  
  chassis.drive_distance(-12,180,12,6,2,0,2000);
  MogoMech.set(false);
  Intake.spin(reverse,12,volt);
  chassis.drive_distance(-35,45,12,6,2,0,2000);
  Intake.stop();
  chassis.drive_distance(13,45,12,6,1,300,2000);

  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);

  chassis.drive_stop(brake);
  Intake.stop();
}

void Right_Blue_Stake_3(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(-72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,-72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,-55,12,12,1,0,2500); //-14
  chassis.drive_distance(-27,-55,6,12,1,100,1500); //3 volts //-25in
  //chassis.drive_distance(-18,50,6,12,1,150,1500);
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(180,12,2,50,2000);
  chassis.drive_distance(19.5,180,12,12,1,300,2500);//

  //Intake alliance line donut
  chassis.turn_to_angle(90,6,1,25,1500);
  Intake.spin(reverse,12,volt);
  wait(250, msec);
  Intake.spin(fwd,12,volt);
  chassis.drive_distance(12,90,6,6,1,999,1500); 



  chassis.drive_distance(-4,45,12,6,1,0,1500);//-4
  chassis.drive_distance(-6,45,12,6,1,0,2000);
  chassis.drive_distance(-6,90,12,6,1,0,2500);//-8
  Intake.spin(reverse,12,volt);
  wait(250, msec);
  Intake.spin(fwd,12,volt);
  chassis.drive_distance(12,90,6,6,0.5,200,1500);//we are splitting this into two parts, so that it can outtake midway //11in
  

  chassis.drive_distance(-12,180,12,6,2,0,2000);
  MogoMech.set(false);
  Intake.spin(reverse,12,volt);
  chassis.drive_distance(-35,45,12,6,2,0,2000);
  Intake.stop();
  chassis.drive_distance(13,45,12,6,1,300,2000);

  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);

  //chassis.drive_distance(4,-45,12,6,1,200,2000);
  chassis.drive_stop(brake);
  Intake.stop();
}

void Entire_Field_AWP(){
  //turn to wallstake and raise arm and neutral mech
  wait(100, msec);
  Intake.spin(fwd,12,volt);
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(9.5,0,12,12,1,150,1500); //10.5
  Intake.spin(reverse,12,volt);
  chassis.turn_to_angle(75,12,2,150,1750);
  //drive to wallstake and score
  chassis.drive_distance(4.5,75,4,12,1,50,1500);
  NeutralPiston.set(false);
  wait(500, msec);

  
  //go to mobile goal and grab it
  chassis.drive_distance(-14,55,12,12,1,100,2500);
  chassis.drive_distance(-24.5,55,6,12,1,150,1500); //3 voltsز
  Intake.stop();
  
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  chassis.turn_to_angle(180,12,1,50,1250);
  Intake.spin(fwd,12,volt);
  chassis.drive_distance(18,180,6,12,2,150,2500);
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(24.5,12,0.5,100,1500);
  chassis.drive_distance(68,22.5,9,12,1,350,3000);
  chassis.drive_distance(-8,22.5,12,12,1,0,1500);
  MogoMech.set(false);

  //turn to new mogo
  chassis.turn_to_angle(125,12,1,50,1500);
  chassis.drive_distance(-26,125,6,12);
  MogoMech.set(true);
  

  
}

void Right_Red_Rush(){
  MogoMech.set(false);
  NeutralPiston.set(true);

  ARMPiston.set(true);
  chassis.drive_distance(43,35,12,3,0.5,0,2500); //protect this line at all costs

  NeutralPiston.set(false);
  wait(300, msec);
  ARMPiston.set(false);


  
  wait(100, msec);
  //chassis.drive_distance(-18,0,12,6);
  //ARMPiston.set(true);
 // chassis.drive_distance(-15,0,12,6,1,0,1500);
  //MogoMech.set(true);

  chassis.drive_distance(-3,0,12,6,1,100,3500);
  chassis.drive_distance(-35,0,12,6,1,0,2500); //-27
  ARMPiston.set(true);
  wait(250, msec);
  chassis.DriveL.spin(fwd,12,volt);
  chassis.DriveR.spin(reverse,6,volt);
  wait(500, msec);
  chassis.DriveL.stop(brakeType::brake);
  chassis.DriveR.stop(brakeType::brake);
  ARMPiston.set(false);
  wait(1000, msec);

  chassis.turn_to_angle(150,12,1,150,3000);
  chassis.drive_distance(-22,150,12,6,1,0,2500); //-22
  MogoMech.set(true);
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(90,12,1,150,2000);
  chassis.drive_distance(30,90,12,6,1,250,2500);

  chassis.turn_to_angle(-90,12,1,150,3000);
  MogoMech.set(false);
  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);
  Intake.spin(fwd,0,volt);
  Intake.stop(brake);
  chassis.drive_distance(44,-45,12,6,1,0,5000);
  //chassis.drive_distance(5,-45,12,6,1,0,2000);
  Intake.stop();
}

void Right_Blue_Rush(){
  MogoMech.set(false);
  NeutralPiston.set(true);

  ARMPiston.set(true);
  chassis.drive_distance(43,-35,12,3,0.5,0,2500); //protect this line at all costs

  NeutralPiston.set(false);
  wait(300, msec);
  ARMPiston.set(false);


  
  wait(100, msec);
  //chassis.drive_distance(-18,0,12,6);
  //ARMPiston.set(true);
 // chassis.drive_distance(-15,0,12,6,1,0,1500);
  //MogoMech.set(true);

  chassis.drive_distance(-3,0,12,6,1,100,3500);
  chassis.drive_distance(-35,0,12,6,1,0,2500); //-27
  ARMPiston.set(true);
  wait(250, msec);
  chassis.DriveL.spin(fwd,12,volt);
  chassis.DriveR.spin(reverse,6,volt);
  wait(500, msec);
  chassis.DriveL.stop(brakeType::brake);
  chassis.DriveR.stop(brakeType::brake);
  ARMPiston.set(false);
  wait(1000, msec);

  chassis.turn_to_angle(-150,12,1,150,3000);
  chassis.drive_distance(-22,-150,12,6,1,0,2500); //-22
  MogoMech.set(true);
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(-90,12,1,150,2000);
  chassis.drive_distance(30,-90,12,6,1,250,2500);

  chassis.turn_to_angle(90,12,1,150,3000);
  MogoMech.set(false);
  R1.setBrake(vex::brakeType::brake);
  R2.setBrake(vex::brakeType::brake);
  R3.setBrake(vex::brakeType::brake);
  L1.setBrake(vex::brakeType::brake);
  L2.setBrake(vex::brakeType::brake);
  L3.setBrake(vex::brakeType::brake);
  Intake.spin(fwd,0,volt);
  Intake.stop(brake);
  chassis.drive_distance(44,45,12,6,1,0,5000);
  //chassis.drive_distance(5,-45,12,6,1,0,2000);
  Intake.stop();
}

void Nothing(){

}

void Right_Blue_Alliance_Stake_1(){
  //turn to wallstake and raise arm and neutral mech
  MogoMech.set(false);
  ARMPiston.set(true);
  NeutralPiston.set(true);
  chassis.drive_distance(10.75,0,12,6,1,200,1500); //10.5
  chassis.turn_to_angle(72.5,12,3,50,1750);
  Intake.stop();

  //drive to wallstake and score
  chassis.drive_distance(5.25,72.5,12,6,0.5,50,1500);//5.5in
  NeutralPiston.set(false);
  wait(500, msec);

  //go to mobile goal and grab it
  chassis.drive_distance(-13,55,12,12,1,0,2500); //-14
  chassis.drive_distance(-27,55,6,12,1,100,1500); //3 volts //-25in
  //chassis.drive_distance(-18,50,6,12,1,150,1500);
  ARMPiston.set(false);
  MogoMech.set(true);
  wait(100, msec);
  //go to donut and intake
  Intake.spin(fwd,12,volt);
  chassis.turn_to_angle(180,12,2,50,2000);
  chassis.drive_distance(19.5,180,12,12,1,300,2500);
  

  chassis.drive_distance(-12,180,12,6,2,0,2000);
  MogoMech.set(false);
  Intake.spin(reverse,12,volt);
  chassis.drive_distance(-35,-45,12,6,2,0,2000);
  Intake.stop();
  chassis.drive_distance(13,-45,12,6,1,300,2000);

  

  chassis.drive_stop(brake);
  Intake.stop();
}

void Right_Blue_Side_1P(){

}




/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}