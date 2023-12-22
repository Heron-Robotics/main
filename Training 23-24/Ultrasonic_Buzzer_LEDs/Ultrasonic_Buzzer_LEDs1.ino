const int trigPin = 7;  // Trig pin connected to Arduino digital pin 7
const int echoPin = 6;  // Echo pin connected to Arduino digital pin 6
const int redLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin = 11;

void setup() {
  Serial.begin(9600);   // Initialize serial communication for debugging
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  long duration, distance;
  
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10us pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse from echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Convert the duration into distance (in cm)
  distance = (duration * 0.034) / 2;
  if(distance<5){
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  }
  else if(distance<15){
	digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);  }
  else{
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }
  
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
}
