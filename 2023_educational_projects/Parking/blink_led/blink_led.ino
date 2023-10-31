
// 11/12/2022
// blink_led.ino
// turn on red light for 1 sec, turn it off, bright green light for 1 sec, turn it off, etc

const int red = 4;
//const int green = 11;

void setup() {
  pinMode(red, OUTPUT);
  //pinMode(green, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH); 
  //digitalWrite(green, LOW);
  delay(1000);
  digitalWrite(red, LOW); 
  //digitalWrite(green, HIGH);
  delay(1000);
}
