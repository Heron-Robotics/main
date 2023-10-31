
// HAVENT MANAGED TO MAKE IT (FULLY) WORKABLE YET

// 12/05/2022
// IDEA
// Making a car move autonoumously, and avoid object collision
// If in danger to collide, look around (0 to 180 degrees vision)
// and decide which direction has the furthest object, and move towards it. 

// TECHNICAL DETAILS
// Servo is used to attach on it an ultrasonic sensor, so it can rotate the device and calculate distance around

// HARDWARE NEEDED: Arduino UNO R3 (obligatory, so it matches shield-motor driver)
//                  Jumper wires
//                  2 * DC motors (5 to 6V)
//                  Motor driver L293D (shield like, covers the whole board,
//                                      apart from 6 analog pins and 4 pins for supply/ ground)
//                  Ultra sonic sesor
//                  Servo motor

#include <Servo.h>
#include <AFMotor.h>

// PINS set to analog values do to lack of digital
const int servo_pin = A5; 
const int trig = A4;
const int echo = A3;

int MAX_SPEED = 100;

AF_DCMotor firstMotor(1);
AF_DCMotor secondMotor(2);
Servo servo;

// forward-declaration of functions writen bellow
void forward();
void backward();
void left();
void right();
void stop_all();
int calc_distance();

void setup() {
  // set up ultra sonic sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  // set up servo
  servo.attach(servo_pin);
  // set (non-changing) speed at DC motors
  firstMotor.setSpeed(MAX_SPEED);
  secondMotor.setSpeed(MAX_SPEED);
  // start communication with terminal/ Serial monitor
  Serial.begin(9600);
}

void loop() {
  forward();
  
  int dist, maxx = 0, s=0; 
  for (int i=0; i<181; i=i+45) {
    servo.write(i);
    dist = calc_distance();
    if (dist > maxx) {
      maxx = dist;
      s = i;
    }
  } 

  servo.write(90);
  delay(200);
  
  if (s < 80) 
    left();
  else if (s>100) 
    right();

 while (calc_distance() > maxx - 8);
 allstop();
 delay(200);
 forward();
 delay(200);
}


int calc_distance() {
  // put your main code here, to run repeatedly:
  int duration, distance;  

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.034) / 2;

  Serial.println(distance); 
  return distance; 
}


// DC MOTOR HANDLING
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
