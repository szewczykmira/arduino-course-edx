/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

int PIN_RED = 12;
int PIN_AMBER = 11;
int PIN_GREEN = 10;
int PIN_PEDESTRIAN_RED = 9;
int PIN_PEDESTRIAN_GREEN = 8;
int PIN_BUTTON = 2;

int buttonState = LOW;

// the setup function runs once when you press reset or power the board
void setup() {  
  // initialize digital pins
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_AMBER, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_PEDESTRIAN_RED, OUTPUT);
  pinMode(PIN_PEDESTRIAN_GREEN, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Set up initial state of lights
  digitalWrite(PIN_PEDESTRIAN_RED, HIGH);
  digitalWrite(PIN_PEDESTRIAN_GREEN, LOW);
  digitalWrite(PIN_GREEN, HIGH);
  delay(3000);
  digitalWrite(PIN_GREEN,LOW);

  // check if button is pressed
  buttonState = digitalRead(PIN_BUTTON);
  
  // this part will always be the same for both procedures
  digitalWrite(PIN_AMBER, HIGH);
  delay(1000);
  digitalWrite(PIN_AMBER, LOW);
  digitalWrite(PIN_RED, HIGH);

  if(buttonState == LOW){
    // if button is not pressed proceed with standard procedure
    delay(3000);
    digitalWrite(PIN_RED, LOW);  
  } else {
    // button is pressed - allow pedestrians to walk
    digitalWrite(PIN_PEDESTRIAN_RED, LOW);
    digitalWrite(PIN_PEDESTRIAN_GREEN, HIGH);
    delay(5000);
    digitalWrite(PIN_RED, LOW);
  }
}
