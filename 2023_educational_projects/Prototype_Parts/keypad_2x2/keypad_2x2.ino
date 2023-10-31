
// 28/04/2022
// Making a 2x2 keypad (out of a 4x4 keypad)
// IMPLEMENTATION: powering 2 rows + 2 columns 
// leaving unplugged (and non-workable) the 2 last rows and the 2 last columns
// Hardware needed: Arduino microcontroller (e.g. UNO R3)
//                  Jumper wires
//                  Keypad 4x4 (or 3x3, or 2x2)

#include <Keypad.h>

const byte ROWS = 2; // number of rows in the keypad
const byte COLS = 2; // number of columns in the keypad

// IF I WANTED 2 PLACES AND 4 WIRES POWERING KEYPAD
char keys[ROWS][COLS] = { // keypad layout
  {'1', '0' },
  {'0', '5' }};
  
byte rowPins[ROWS] = {13, 11}; // pins connected to keypad rows
byte colPins[COLS] = {12, 10}; // pins connected to keypad columns

// create Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup() {
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  char key = keypad.getKey(); // read keypad input
  
  if (key != '\0') { // if a key is pressed
    Serial.print("Key Pressed: ");
    Serial.println(key); // display the key on the serial monitor
  }
}
