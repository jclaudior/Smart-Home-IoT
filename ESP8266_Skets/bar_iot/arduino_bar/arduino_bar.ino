#include <Wire.h>
#define drinkI 5
#define drinkII 6
#define drinkIII 7
char c;

void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Serial.begin(9600);           /* start serial for debug */
 pinMode(drinkI, OUTPUT);
 pinMode(drinkII, OUTPUT);
 pinMode(drinkIII, OUTPUT);
}

void loop() {  
 if ( c == 'a'){
 digitalWrite(drinkI, 1);
 delay(2000);
 digitalWrite(drinkI, 0);
 c = 'q';
 }
 if ( c == 'b'){
 digitalWrite(drinkII, 1);
 delay(2000);
 digitalWrite(drinkII, 0);
 c = 'q';
 }
 if ( c == 'c'){
 digitalWrite(drinkIII, 1);
 delay(2000);
 digitalWrite(drinkIII, 0);
 c = 'q';
 }
 
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    c = Wire.read();      /* receive byte as a character */
    Serial.print(c);
  }
   Serial.println(); 
          /* to newline */
}

// function that executes whenever data is requested from master

