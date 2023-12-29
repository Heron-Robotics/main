const int buttonPin = 13;
const int buzzerPin = 12;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW){
    tone(buzzerPin, 980);
    delay(100);
  }
  noTone(buzzerPin);
}