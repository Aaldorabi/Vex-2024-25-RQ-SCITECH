#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

void drive_test();
void First_Auton();
void swing_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();



/*
void Entire_Field_AWP();

void Red_Right_Side_Stake();

//Red Side Right
void Right_Red_Rush();
void Right_Red_Alliance_Stake_1();
void Right_Red_Side_1P();

//Red Side Left
void Left_Red_Stake(); 
void Left_Red_Alliance_Stake_1();
void Left_Red_Alliance_Stake_2();
void Left_Red_Alliance_Stake_3();

//Blue side Right
void Right_Blue_Stake(); 
void Right_Blue_Stake_1();
void Right_Blue_Stake_2();
void Right_Blue_Stake_3();

//Blue Side Left
void Right_Blue_Rush();
void Right_Blue_Alliance_Stake_1();
void Right_Blue_Side_1P();
*/


//Red Side Right
void Right_Red_Rush(); 
void Right_Red_Alliance_Stake_1();
void Right_Red_Side_1P(); //DNE
void Right_Red_Stake();

//Red Side Left
void Left_Red_Stake(); 
void Left_Red_Alliance_Stake_1();
void Left_Red_Alliance_Stake_2();
void Left_Red_Alliance_Stake_3();

//Blue side Right
void Right_Blue_Stake(); 
void Right_Blue_Stake_1();
void Right_Blue_Stake_2();
void Right_Blue_Stake_3();

//Blue Side Left
void Right_Blue_Rush();
void Right_Blue_Alliance_Stake_1();
void Right_Blue_Side_1P(); //DNE
void Right_Blue_Stake();

//etc
void Entire_Field_AWP();
void skills_1();
void Nothing();