
// 17/03/2023
// traffic_light_and_servo_bar.ino
// every 3 sec, a red LED is on and a servo bar is closed (0 degrees)
// then change, turn off red LED, and green LED and a servo bar is open (110 degress) 

#include <Servo.h>

const int servo_pin = 9; 
Servo servo;

const int red = 13;
const int green = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  servo.attach(servo_pin); 
}

void loop() {

  // red light on AND bar (servo) closed/ down 
  digitalWrite(red, HIGH); 
  digitalWrite(green, LOW);
  servo.write(0);
  delay(3000);
  
  // green light on AND bar (servo) open/ up 
  digitalWrite(red, LOW); 
  digitalWrite(green, HIGH);
  servo.write(110);
  delay(3000);

}
