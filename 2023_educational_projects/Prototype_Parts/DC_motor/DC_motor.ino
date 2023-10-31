
// Making 2 DC motor drivers move forward, backward, left, right and stop 

// HARDWARE NEEDED: Arduino Uno R3 (SPECIFICALLY THIS to match motor driver)
//                  2 * DC motors 
//                  Motor driver L293D (4-motor bridge specially for Arduino UNO R3)
//                  2 * Wheels (optional, to showing movement)

#include <AFMotor.h>

int MAX_SPEED = 255;
// FORWARD -> pushes motor to the front direction (+180 degrees)
// BACKWARD -> pushes motor to the back direction (-180 degrees)
// RELEASE -> stops motors from moving

// parameter showing what number of port (1 to 4) is motor connected
AF_DCMotor firstMotor(1);
AF_DCMotor secondMotor(2);

void setup(){
  firstMotor.setSpeed(MAX_SPEED);
  secondMotor.setSpeed(MAX_SPEED);
}

void loop(){
  forward();
  delay(2000);
  backward();
  delay(2000);
  left();
  delay(2000);
  right();
  delay(2000);
  allstop();
  delay(2000);
}

void forward(){
  // both wheels pushing forward (straight move)
  firstMotor.run(FORWARD);
  secondMotor.run(FORWARD);
}
void backward(){
  // both wheels pushing backward (straight move)
  firstMotor.run(BACKWARD);
  secondMotor.run(BACKWARD);
}
void left(){
  // first wheel (right) stops, second wheel (left) pushing
  // NEEDS common axis to push car
  firstMotor.run(RELEASE);
  secondMotor.run(FORWARD);
}
void right(){
  // second wheel (right) stops, first wheel (left) pushing
  // NEEDS common axis to push car
  firstMotor.run(FORWARD);
  secondMotor.run(RELEASE);
}
void allstop(){
  // stop circular movement in both wheels
  firstMotor.run(RELEASE);
  secondMotor.run(RELEASE);
}
