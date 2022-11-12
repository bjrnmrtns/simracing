/*#include <BleGamepadConfiguration.h>
#include <BleConnectionStatus.h>
#include <BleGamepad.h>

#include <Arduino.h>
#include <BleGamepad.h>

struct Button {
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

Button button1 = {23, 0, false};

void IRAM_ATTR isr() {
  button1.numberKeyPresses++;
  button1.pressed = true;
}

BleGamepad bleGamepad;

 int outputA = 8;
 int outputB = 4;

 int counter = 0; 
 int aState;
 int aLastState;

void setup()
{
    pinMode (outputA,INPUT);
    pinMode (outputB,INPUT);
    
    pinMode(button1.PIN, INPUT);
    attachInterrupt(button1.PIN, isr, FALLING);
    aLastState = digitalRead(outputA); 
    Serial.begin(115200);
    //bleGamepad.begin();
    // The default bleGamepad.begin() above enables 16 buttons, all axes, one hat, and no simulation controls or special buttons
}

void doBle()
{
  if (bleGamepad.isConnected()) {
    bleGamepad.press(BUTTON_5);
    bleGamepad.release(BUTTON_5);
  }
}

void loop()
{
    //doBle();
    //delay(500);
    if (button1.pressed) {
      //Serial.printf("Button has been pressed %u times\n", button1.numberKeyPresses);
      button1.pressed = false;
    }
 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
}
*/
/*
#include <Arduino.h>

bool pressed;
uint32_t number_of_presses = 0;
unsigned long last_time_button_pressed = 0; 

void IRAM_ATTR isr() {
    unsigned long current_time = millis();
    if(current_time - last_time_button_pressed > 50)
    {
        pressed = true;
        number_of_presses++;
        last_time_button_pressed = current_time;
    }
}

void setup() {
  Serial.begin(115200);
  pinMode(23, INPUT_PULLUP);
  //attachInterrupt(23, isr, FALLING);
  //pressed = false;
}
 
void loop() {
  //if(pressed) {
  //  Serial.printf("Button is pressed %u number of times\n", number_of_presses);
  //  pressed = false;
  //}
  if(!digitalRead(23)) {
    Serial.println("Button pressed");
  }
  delay(1);
}*/
#include <Arduino.h>
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop() {
  Serial.println("Loop");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
}
