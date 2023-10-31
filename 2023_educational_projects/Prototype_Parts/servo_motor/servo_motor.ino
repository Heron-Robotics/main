
// 17/03/2023
// test_a_servo_motor.ino
// MAKES A SERVO MOTOR SHIFT FROM 0 TO 90 DEGREES (AND BACK) EVERY 1 SEC

#include <Servo.h>

const int servo_pin = A5; 
Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servo_pin); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // value from 0 to 180 
  servo.write(180);
  delay(1000);
  servo.write(0);
  delay(1000);
}
