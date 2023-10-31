
// 28/04/2022
// PROTOTYPE for using keypad (numpad) 
// Hardware needed: Arduino microcontroller (e.g. UNO R3)
//                  Jumper wires
//                  Keypad 4x4 


#include <Keypad.h>

const byte ROWS = 4; // number of rows in the keypad
const byte COLS = 4; // number of columns in the keypad

char keys[ROWS][COLS] = { // keypad layout
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// KEYPAD connections 
// 8 holes to plug in, the first 4 are black, and the last 4 are white
// Black is for rows (?) and starts counting them as 0, 1, 2, 3 (top - down)
// White is for columns (?) and starts countring them as 0, 1, 2, 3 (left - right)

byte rowPins[ROWS] = {12, 12, 10, 7}; // pins connected to keypad rows
byte colPins[COLS] = {11, 4, 6, 5}; // pins connected to keypad columns

// create Keypad object to connect with hardware
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
