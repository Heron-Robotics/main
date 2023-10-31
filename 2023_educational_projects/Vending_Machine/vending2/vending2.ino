#include <Stepper.h>
#include <Keypad.h>

// Define the number of steps per revolution
const int stepsPerRevolution = 1000;
const int RPM = 30;

// Initialize the stepper motor object
Stepper Stepper1(stepsPerRevolution, 2, 3, 4, 5);
Stepper Stepper2(stepsPerRevolution, 6, 7, 8, 9);

const byte ROWS = 2; // number of rows in the keypad
const byte COLS = 2; // number of columns in the keypad

char keys[ROWS][COLS] = { // keypad layout
  {'1', '0' },
  {'0', '9' }};

byte rowPins[ROWS] = {13, 11}; // pins connected to keypad rows
byte colPins[COLS] = {12, 10}; // pins connected to keypad columns

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); // create Keypad object

void setup() {
  // Set the speed of the stepper motor in RPM
  Serial.begin(9600);
  Stepper1.setSpeed(RPM);  
  Stepper2.setSpeed(RPM);
}

void loop() {

  char key = keypad.getKey(); // read keypad input
  
  if (key != '\0') { // if a key is pressed
    Serial.print("Key Pressed: ");
    Serial.println(key); // display the key on the serial monitor
  }

  if (key == '1') {
    for (int i = 0; i < 4; i++ )
      Stepper1.step(-stepsPerRevolution);
  }
  else if (key == '9') {
    for (int i = 0; i < 4; i++ )
      Stepper2.step(-stepsPerRevolution);
  }
  
}
