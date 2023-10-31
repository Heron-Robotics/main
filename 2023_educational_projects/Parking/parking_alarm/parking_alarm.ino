const int redLed = 12;
const int yelLed = 11;
const int buzzer = 6;
const int trig = 3;
const int echo = 4;

void setup() {
  // put your setup code here, to run once:

  //LEDS
  pinMode(redLed, OUTPUT);
  pinMode(yelLed, OUTPUT);

  //BUZZER
  pinMode(buzzer, OUTPUT);

  //DISTANCE SENSOR
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  long duration;
  long distance;
  
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  pinMode(echo, INPUT);
  duration = pulseIn(echo,HIGH);
  //delayMicroseconds(100);
  Serial.println(duration);
  distance = ( duration * 0.034 ) / 2;
  delayMicroseconds(20);
  Serial.print("Distance = ");
  Serial.println(distance);
  
  if (distance <= 15 && distance >= 0){
    digitalWrite(yelLed, HIGH);
    digitalWrite(redLed, HIGH);
    tone(buzzer, 400);
  }
  else if (distance <= 30){
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    digitalWrite(yelLed, HIGH);
  } else {
    noTone(buzzer);
    digitalWrite(redLed, LOW);
    digitalWrite(yelLed, LOW);
  }


  

}
