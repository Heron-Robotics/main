
# ARDUINO FILE NAME: distance_buzzer1.ino

CIRCUIT IMAGE NAME: circ_eikona.png 

CREATORS: 
 
**Olga Saridou,
Konstantina Deligianni,
Giorgos Karanikolopoulos**
-

PURPOSE OF CIRCUIT:

This circuit measures the distance to nearest objects. If the distance is less than 15 cm, then the buzzer sounds.

HARDWARE USED: 
Arduino UNO R3
Wires
Buzzer (Piezo)
Ultrasonic distance sensor

HARDWARE CONNECTIONS:

References to : 

Globals/ Constants on code (name that matches with part/port/pin of equipment)
-The trigger pin is reffered to as "triger", type of integer, with constant scope. This 
constant is matched with the value of "3".
-The echo pin is reffered to as "echo", type of integer, with constant scope. This 
constant is matched with the value of "4".
-The buzzer pin is reffered to as "buzzer", type of integer, with constant scope. This 
constant is matched with the value of "10".
-The distance is reffered to as "distance", type of integer, with global scope. This 
global is matched with the value of "0".
-The duration is reffered to as "duration", type of integer, with global scope. This 
global is matched with the value of "0".