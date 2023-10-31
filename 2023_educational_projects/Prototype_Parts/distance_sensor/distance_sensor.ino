
// 11/12/2022
// distance_sensor.ino
// Calculates distance and prints it on serial terminal 

const int trig = A4;
const int echo = A3;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  Serial.begin(9600);
}

void loop() {
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
}
