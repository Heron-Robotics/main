
// 17/03/2023
// traffic_light_and_servo_bar_and_distance_sensor.ino
// every 3 sec, a red LED is on and a servo bar is closed (0 degrees)
// then change, turn off red LED, and green LED and a servo bar is open (110 degress) 

#include <Servo.h>

const int servo_pin = 9; 
Servo servo;

const int red = 7;
const int green = 8;
const int trig = 3;
const int echo = 2;

const int cm_to_open_bar = 20;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  servo.attach(servo_pin);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  Serial.begin(9600);
}

void loop() {
  // Calculate distance 
  int duration, distance;
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.034) / 2;
  Serial.println(distance); 

  
  // check distance from object
  if (distance < cm_to_open_bar) {
    // green light on AND bar (servo) open/ up 
    digitalWrite(red, LOW); 
    digitalWrite(green, HIGH);
    servo.write(110);
    delay(1500);
  }
  else{
    // red light on AND bar (servo) closed/ down 
    digitalWrite(red, HIGH); 
    digitalWrite(green, LOW);
    servo.write(0);
  }
  
 

}
