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
// Controller1          controller                    
// FR                   motor         1               
// FL                   motor         2               
// BR                   motor         9               
// BL                   motor         10              
// Intake               motor         11              
// valve                led           A               
// EndGame              led           B               
// Intake2              motor         12              
// Shooter              motor         19              
// Shooter2             motor         20              
// PC                   pot           C               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

bool vToggle = false;
bool eToggle = true;
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

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
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
void switchValve(){
  vToggle = !vToggle;
}
void endGame(){
  eToggle = !eToggle;
}

void stopAll(){
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();

}

void goBackward(double t){
  FR.spin(forward,100, percent);
  FL.spin(forward,100, percent);
  BR.spin(forward,100, percent);
  BL.spin(forward,100, percent);
  wait(t, seconds);
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();

}
void goForward(double t){
  FR.spin(reverse,100, percent);
  FL.spin(reverse,100, percent);
  BR.spin(reverse,100, percent);
  BL.spin(reverse,100, percent);
  wait(t, seconds);
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();
}

void strafeLeft(double t){
  FR.spin(reverse,100, percent);
  FL.spin(forward,100, percent);
  BR.spin(forward,100, percent);
  BL.spin(reverse,100, percent);
  wait(t, seconds);
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();
}

void strafeRight(double t){
  FR.spin(forward,100, percent);
  FL.spin(reverse,100, percent);
  BR.spin(reverse,100, percent);
  BL.spin(forward,100, percent);
  wait(t, seconds);
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();
}

void turnLeft(double t){
  FR.spin(reverse,100, percent);
  FL.spin(forward,100, percent);
  BR.spin(reverse,100, percent);
  BL.spin(forward,100, percent);
  wait(t, seconds);
  stopAll();
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();
}

void turnRight(double t){
  FR.spin(forward,100, percent);
  FL.spin(reverse,100, percent);
  BR.spin(forward,100, percent);
  BL.spin(reverse,100, percent);
  wait(t, seconds);
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();
}

void warm(double t){
  Shooter.spin(forward,100, percent);
  Shooter2.spin(forward,100, percent);
  wait(t , seconds);
}
void suckStill(double t){
  Intake.spin(forward,100, percent);
  Intake2.spin(forward,100, percent);
  wait(t, seconds);
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();
}
void suck(double t){
  FR.spin(forward,100, percent);
  FL.spin(forward,100, percent);
  BR.spin(forward,100, percent);
  BL.spin(forward,100, percent);
  Intake.spin(forward,100, percent);
  Intake2.spin(forward,100, percent);
  wait(t, seconds);
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();
}
void shoot(double t, double x){
  Shooter.spin(forward,100, percent);
  Shooter2.spin(forward,100, percent);
  valve.on();
  wait(t , seconds);
  valve.off();
  Shooter.spin(forward,100, percent);
  Shooter2.spin(forward,100, percent);
  Intake.spin(forward,100, percent);
  Intake2.spin(forward,100, percent);
  wait(x , seconds);
}
void roller(double t){
  FR.spin(reverse,40, percent);
  FL.spin(reverse,40, percent);
  BR.spin(reverse,40, percent);
  BL.spin(reverse,40, percent);
  Intake.spin(forward,100, percent);
  Intake2.spin(forward,100, percent);
  wait(t, seconds);
  FR.stop();
  FL.stop();
  BR.stop();
  BL.stop();
  Intake.stop();
  Intake2.stop();
  Shooter.stop();
  Shooter2.stop();
}
void doNothing(double t){
  stopAll();
  wait(t, seconds);
}

void autonomous(void) {
//Right Auto rollers
  if(PC.angle(degrees) > -135 && PC.angle(degrees) < -100){
    goBackward(1.5);
    turnRight(.6);
    goBackward(.2);
    roller(.3);

  }
  //Right Auto Shoot Preload and Roller
  else if(PC.angle(degrees) > -99 && PC.angle(degrees) < -70){
    goForward(.8);
    warm(1.2);
    shoot(.2 , .8);
    shoot(.2 , .8);
    strafeRight(1.2);
    turnRight(.8);
    goForward(.8);
    roller(.8);
  }
  //Right Auto
  else if(PC.angle(degrees) > -69 && PC.angle(degrees) < -35){
    goForward(.8);
    suck(.5);
    suckStill(.4);
    turnRight(.2);
    warm(3);
    shoot(.2 , .8);
    shoot(.2 , .8);
    shoot(.2 , .8);
    turnRight(.8);
    goForward(1.2);
    turnRight(.3);
    roller(.3);
  }
  //Right Auto
  else if(PC.angle(degrees) > -34 && PC.angle(degrees) < 0){
    goForward(.6);
    warm(1.2);
    shoot(.2 , .8);
    shoot(.2 , .8);
    turnLeft(0.6);
    suck(2);
    turnRight(.6);
    warm(1.2);
    shoot(.2 , .8);
    shoot(.2 , .8);
    shoot(.2 , .8);
    turnRight(.6);
    goForward(3);
    turnRight(.2);
    roller(.3);
  }
  //Left Auto Roller only
  else if(PC.angle(degrees) > 1 && PC.angle(degrees) < 35){
    roller(.3);
  }
  //Left Auto Shoot only
  else if(PC.angle(degrees) > 36 && PC.angle(degrees) < 70){
    goForward(.6);
    warm(1.2);
    shoot(.2 , .8);
    shoot(.2 , .8);
    strafeLeft(.6);
    turnLeft(.8);
    goForward(.4);
    roller(.3);
  }
  //Left Auto Pick up one and shoot
  else if(PC.angle(degrees) > 71 && PC.angle(degrees) < 100){
    suck(1);
    turnLeft(.2);
    warm(1.2);
    shoot(.2 , .8);
    shoot(.2 , .8);
    shoot(.2 , .8);
    turnLeft(.9);
    goForward(1.4);
    turnLeft(.3);
    goForward(.3);
    roller(.3);
  }
  //Left Auto Pick up four and shoot six
  else{
    suck(1);
    turnLeft(.2);
    warm(1.2);
    shoot(.2 , .8);
    shoot(.2 , .8);
    shoot(.2 , .8);
    turnRight(.6);
    goForward(.6);
    suck(3);
    turnLeft(.6);
    warm(1.2);
    shoot(.2 , .8);
    shoot(.2 , .8);
    shoot(.2 , .8);
    
  }


  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}
//If Colby uses this code to operate the robot he submits all of his rights as a project manager to Tyler.
/*---------------------------------------------------------------------------*/
/*                                                                          */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/



void usercontrol(void) {
  // User control code here, inside the loop

  Controller1.ButtonY.pressed(endGame);

  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    
    if(Controller1.ButtonA.pressing()){
      Intake.spin(forward, 100, percent);
      Intake2.spin(forward, 100, percent);
    }
    else{
      Intake.stop();
      Intake2.stop();
    }
    
    if(Controller1.ButtonB.pressing()){
      Intake.spin(reverse, 100, percent);
      Intake2.spin(reverse, 100, percent);
    }
    else{
      Intake.stop();
      Intake2.stop();
    }
    if(Controller1.ButtonR1.pressing()){
      Shooter.spin(forward, 50, percent);
      Shooter2.spin(forward, 50, percent);
    }
    else if(Controller1.ButtonR2.pressing()){
      Shooter.spin(forward, 60, percent);
      Shooter2.spin(forward, 60, percent);
    }
    else if(Controller1.ButtonL1.pressing()){
      Shooter.spin(forward, 80, percent);
      Shooter2.spin(forward, 80, percent);
    }
    else if(Controller1.ButtonL2.pressing()){
      Shooter.spin(forward, 100, percent);
      Shooter2.spin(forward, 100, percent);
    }
    else{
      Shooter.stop();
      Shooter2.stop();
    }
    if(Controller1.ButtonUp.pressing()){
      switchValve();
      wait(0.15, seconds);
      switchValve();
    }
    else{
      vToggle = true;
    }

    FR.spin(forward,(Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent) - Controller1.Axis1.position(percent)), percent);
    FL.spin(forward,(Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent) + Controller1.Axis1.position(percent)), percent);
    BR.spin(forward,(Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent) - Controller1.Axis1.position(percent)), percent);
    BL.spin(forward,(Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent) + Controller1.Axis1.position(percent)), percent);

    if(vToggle){
      valve.on();
    }
    else{
      valve.off();
    }

    if(eToggle){
      EndGame.on();
    }
    else{
      EndGame.off();
    }


    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
// returns greatest value of 4 numbers with 100 default if all are less than 100
  double greatest(double FL, double FR, double BL, double BR) {
    if ((FL >= 100) || (FR >= 100) || (BL >= 100) || (BR >= 100)) {
      double finalnum = FL;
      if (finalnum <= FR) {
        finalnum = FR;
      }
      if (finalnum <= BL) {
        finalnum = BL;
      }
      if (finalnum <= BR) {
        finalnum = BR;
      }
      if (finalnum != 0) {
        return finalnum;
      } else {
        return 100;
      }
    } else {
      return 100;
    }
  }
void updateControllerAxis() {
    double LXaxis = Controller1.Axis4.position();
    double LYaxis = Controller1.Axis3.position();
    double RXaxis = Controller1.Axis1.position() / 2;
    //updates
    double FLspeed = LYaxis + LXaxis + RXaxis;
    double FRspeed = LYaxis - LXaxis - RXaxis;
    double BLspeed = LYaxis - LXaxis + RXaxis;
    double BRspeed = LYaxis + LXaxis - RXaxis;

    double under = greatest(fabs(FLspeed), fabs(FRspeed), fabs(BLspeed), fabs(BRspeed)) /100;
    FLspeed = (FLspeed / under);
    FRspeed = (FRspeed / under);
    BLspeed = (BLspeed / under);
    BRspeed = (BRspeed / under);
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

  
  wait(100, msec);
}



