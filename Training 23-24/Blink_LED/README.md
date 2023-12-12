--------------------------------------------------
### ARDUINO FILE NAME: blink_LED_12.ino
---------------------------------------------------

CIRCUIT IMAGE NAME: circ_blink_LED_12.png

CREATORS: 1. Maria Orfanaki

---------------------------------------------------
### PURPOSE OF CIRCUIT: 
---------------------------------------------------
#### This circuit makes a LED shine for 1 second, then turns it off for another 1 sec, and repeats.
---------------------------------------------------
### HARDWARE USED: 
 - Arduino UNO R3 
 - Breadboard, 
 - 2 wires
 - 1 resistor (330Ω)
 - 1 LED (red)
---------------------------------------------------
### HARDWARE CONNECTIONS: 
 - GLOBALS/ CONSTANTS 
   - The red LED is reffered to as "LED", type of integer (constant), with global scope. This constant is matched with the value of "12".

 - CRUSIAL CONNECTIONS
   - The LED and the resistor are placed in the breadboard. 
   - The LED's short leg goes to a GND pin straight to the Arduino board. To do so, a (black) wire is used.
   - The LED's long leg is plugged in Digital Pin (PWD) number 12. Before reaching PWD 12, there is a resistor in between. To do so, a (green) wire is used.
 
