#include <Arduino.h>
#include <PS2Kbd.h>
#include <BleKeyboard.h>


#define KEYBOARD_DATA 19
#define KEYBOARD_CLK  18

PS2Kbd keyboard(KEYBOARD_DATA, KEYBOARD_CLK);
BleKeyboard bleKeyboard;

void setup() {
    Serial.begin(115200);
    keyboard.begin();
    bleKeyboard.begin();
    Serial.println("Starting BLE work!");
}

void loop() {
    if (keyboard.available()) {
      char c = keyboard.read();
      Serial.print(c);
      if(bleKeyboard.isConnected()){
        bleKeyboard.print(c);
      }   
    }
}
