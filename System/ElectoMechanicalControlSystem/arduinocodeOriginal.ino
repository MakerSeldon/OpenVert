/*
  Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  The circuit:
  - Use the onboard LED.
  - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
    and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
    is set to the correct LED pin independent of which board is used.
    If you want to know what pin the on-board LED is connected to on your
    Arduino model, check the Technical Specs of your board at:
    https://www.arduino.cc/en/Main/Products

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

// constants won't change. Used here to set a pin number:
const int ledPin =  11;// the number of the LED pin
const int INRelayPin =  10;// the number of the LED pin
const int OUTRelayPin =  9;// the number of the LED pin
const int EXHAUSTRelayPin =  6;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
int INRelayState = LOW;             // ledState used to set the LED
int OUTRelayState = LOW;             // ledState used to set the LED
int EXHAUSTRelayState = LOW;             // ledState used to set the LED
int LatchState = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long OUTERinterval = 5000;           // interval at which to blink (milliseconds)
const long INNERinterval = 2500;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(INRelayPin, OUTPUT);
  pinMode(OUTRelayPin, OUTPUT);
  pinMode(EXHAUSTRelayPin, OUTPUT);
  // set the LED with the ledState of the variable:
  // Set to FIll Accumulator
  digitalWrite(ledPin, LOW);
  digitalWrite(INRelayPin, HIGH);
  digitalWrite(OUTRelayPin, LOW);
  digitalWrite(EXHAUSTRelayPin, HIGH);

}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= OUTERinterval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis; 
    LatchState = HIGH;
    ledState = HIGH;
  } 


  if (currentMillis - previousMillis >= INNERinterval) {
    LatchState = LOW;
  }
  if (LatchState == HIGH){
    // At the PWM on period
    ledState = HIGH;     //Turn LED on
    INRelayState = HIGH; //Open INput valve
    OUTRelayState = LOW; //Close OUTput valve
    EXHAUSTRelayState = INRelayState; //Close OUTput valve
    } 
    else{
       ledState = LOW;
       INRelayState =LOW;
       OUTRelayState =HIGH;
       EXHAUSTRelayState =INRelayState;
    }
    // set the LED with the ledState of the variable:
    // writes on every loop
    digitalWrite(ledPin, ledState);
    digitalWrite(INRelayPin, INRelayState);
    digitalWrite(OUTRelayPin, OUTRelayState);
    digitalWrite(EXHAUSTRelayPin, EXHAUSTRelayState);
    
  
}
