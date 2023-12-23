const int echo = 4;
const int triger = 3;
const int buzzer = 10;
int duration = 0;
int distanceCm = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triger, LOW);
  delayMicroseconds(2);
  digitalWrite(triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(triger, LOW);


  duration = pulseIn(echo, HIGH);
  distanceCm = duration*0.034/2;

   if (distanceCm < 15)
      digitalWrite(buzzer, HIGH);
    else
      digitalWrite(buzzer, LOW);
    
}