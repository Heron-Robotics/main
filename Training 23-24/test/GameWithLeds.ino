const long int interval = 3000;
const int rows = 4;
const int leds[rows] = {0, 3, 4, 5};
const int buttons[rows] = {0, 11, 12, 13};
long int previousMillis = 0;
const int buzzer = 2;
const int Analog0 = 0;

void setup()
{
  pinMode(buttons[1], INPUT);
  pinMode(buttons[2], INPUT);
  pinMode(buttons[3], INPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  pinMode(leds[3], OUTPUT);
}

void loop()
{
  long int currentMillis = millis();
  bool flag;
  randomSeed(analogRead(Analog0));
  long int timeFrame = random(2, 6);
  long int trigerLed = random(1, 4);
  Serial.println(trigerLed);
  while(true){
    if(currentMillis - previousMillis >= timeFrame * 1000){
      digitalWrite(leds[trigerLed], HIGH);
      flag = true; // If the flag remains true, the user did not pressed the button on time.
      previousMillis = millis();
      while(currentMillis - previousMillis < 3000){
        if(digitalRead(buttons[trigerLed]) == HIGH){
          flag = false;
          digitalWrite(leds[trigerLed], LOW);
          delay(100);
          digitalWrite(leds[trigerLed], HIGH);
          delay(500);
          digitalWrite(leds[trigerLed], LOW);         
		  delay(500);
          digitalWrite(leds[trigerLed], HIGH);
          delay(500);
          digitalWrite(leds[trigerLed], LOW);         
		  delay(500);
          currentMillis = millis();
          break;
        }
        currentMillis = millis();
      
      }
      if(flag){
      	digitalWrite(leds[trigerLed], LOW);
        digitalWrite(buzzer, HIGH);
        delay(2000);
        digitalWrite(buzzer, LOW);
        currentMillis = millis();
        break;
      }else{
        currentMillis = millis();
        break;
      }
    
      
    }
  currentMillis = millis();
  }
  delay(3000); // The program "Freezes" for 3 seconds.
  
  
}