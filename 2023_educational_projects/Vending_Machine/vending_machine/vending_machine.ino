
// Vending machine
// Hardware needed: Arduino microcontroller (UNO R3)
//                  Jumper wires (Female to Male)
//                  2 * Stepper motor (of 5V, 28BYJ-48 DC)
//                  2* Driver for stepper motor 
//                  Breadboard

#include <Stepper.h>
#include <Keypad.h>

const byte ROWS = 2; // number of rows in the keypad
const byte COLS = 2; // number of columns in the keypad

char keys[ROWS][COLS] = { {'1', '2' },
                          {'4', '5' } };

byte rowPins[ROWS] = {13, 12}; // pins connected to keypad rows
byte colPins[COLS] = {3, 2}; // pins connected to keypad columns

// Define the number of steps per revolution
const int stepsPerRevolution = 1000;
const int RPM = 15;

// Initialize the stepper motor object
Stepper Stepper1(stepsPerRevolution, 8, 10, 9, 11);
Stepper Stepper2(stepsPerRevolution, 7, 6, 5, 4);

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

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
    Stepper1.step(-stepsPerRevolution);
    Stepper1.step(-stepsPerRevolution);
    Stepper1.step(-stepsPerRevolution);
    Stepper1.step(-stepsPerRevolution);
  }
  else if (key == '2') {
    Stepper2.step(-stepsPerRevolution);
    Stepper1.step(-stepsPerRevolution);
    Stepper1.step(-stepsPerRevolution);
    Stepper1.step(-stepsPerRevolution);
  }
  
}
