// Author: Christian Merrill
// Version: 0.0-dev
// License: MIT 2.0

#include <Wire.h>
#include <Joystick.h>

// Analog Inputs
// flaps and wingsweep on F14 panel addition only
#define knob1 A0
#define knob2 A1
#define flaps A2
#define wingSweep A3

int knob1Axis = 0;
int knob2Axis = 0;
int flapsAxis = 0;
int wingSweepAxis = 0;

// Digital Inputs 

// 30 total on center
// 9 total on F14 side pannel

//F14 Buttons
#define f14Button1 1
#define f14Button2 2
#define f14Button3 3
#define f14Button4 4
#define f14Button5 14
#define f14Button6 15
#define f14Button7 16
#define f14Button8 17
#define f14Button9 18

int lastF14Button1 = 0;
int lastF14Button2 = 0;
int lastF14Button3 = 0;
int lastF14Button4 = 0;
int lastF14Button5 = 0;
int lastF14Button6 = 0;
int lastF14Button7 = 0;
int lastF14Button8 = 0;
int lastF14Button9 = 0;

#define centerButton1 22
#define centerButton2 24
#define centerButton3 26
#define centerButton4 28
#define centerButton5 30
#define centerButton6 32
#define centerButton7 34
#define centerButton8 36
#define centerButton9 38
#define centerButton10 40
#define centerButton11 42
#define centerButton12 44
#define centerButton13 46
#define centerButton14 48
#define centerButton15 50
#define centerButton16 52
#define centerButton17 23
#define centerButton18 25
#define centerButton19 27
#define centerButton20 29
#define centerButton21 31
#define centerButton22 33
#define centerButton23 35
#define centerButton24 37
#define centerButton25 39
#define centerButton26 41
#define centerButton27 43
#define centerButton28 45
#define centerButton29 47
#define centerButton30 49


int lastCenterButton1 = 0;
int lastCenterButton2 = 0;
int lastCenterButton3 = 0;
int lastCenterButton4 = 0;
int lastCenterButton5 = 0;
int lastCenterButton6 = 0;
int lastCenterButton7 = 0;
int lastCenterButton8 = 0;
int lastCenterButton9 = 0;
int lastCenterButton10 = 0;
int lastCenterButton11 = 0;
int lastCenterButton12 = 0;
int lastCenterButton13 = 0;
int lastCenterButton14 = 0;
int lastCenterButton15 = 0;
int lastCenterButton16 = 0;
int lastCenterButton17 = 0;
int lastCenterButton18 = 0;
int lastCenterButton19 = 0;
int lastCenterButton20 = 0;
int lastCenterButton21 = 0;
int lastCenterButton22 = 0;
int lastCenterButton23 = 0;
int lastCenterButton24 = 0;
int lastCenterButton25 = 0;
int lastCenterButton26 = 0;
int lastCenterButton27 = 0;
int lastCenterButton28 = 0;
int lastCenterButton29 = 0;
int lastCenterButton30 = 0;

Joystick_ Joystick(0x15, JOYSTICK_TYPE_JOYSTICK, 39, 0, false, false, true, true, true, true, false, false, false, false, false);
const bool initAutoSendState = false;
const int smoothing = 1023;

int setButtonState(int currentButtonState, int previousButtonState, int button){
  // Function to update button states and update the joystick
  int newButtonState;
  if (currentButtonState != previousButtonState){
    Joystick.setButton(button, currentButtonState);
    newButtonState = currentButtonState;
    return newButtonState;
  }
  else {
    newButtonState = previousButtonState;
    return newButtonState;
  }
}

void setup() {
  // put your setup code here, to run once:

  pinMode(f14Button1, INPUT_PULLUP);
  pinMode(f14Button2, INPUT_PULLUP);
  pinMode(f14Button3, INPUT_PULLUP);
  pinMode(f14Button4, INPUT_PULLUP);
  pinMode(f14Button5, INPUT_PULLUP);
  pinMode(f14Button6, INPUT_PULLUP);
  pinMode(f14Button7, INPUT_PULLUP);
  pinMode(f14Button8, INPUT_PULLUP);
  pinMode(f14Button9, INPUT_PULLUP);
  
  pinMode(centerButton1, INPUT_PULLUP);
  pinMode(centerButton2, INPUT_PULLUP);
  pinMode(centerButton3, INPUT_PULLUP);
  pinMode(centerButton4, INPUT_PULLUP);
  pinMode(centerButton5, INPUT_PULLUP);
  pinMode(centerButton6, INPUT_PULLUP);
  pinMode(centerButton7, INPUT_PULLUP);
  pinMode(centerButton8, INPUT_PULLUP);
  pinMode(centerButton9, INPUT_PULLUP);
  pinMode(centerButton10, INPUT_PULLUP);
  pinMode(centerButton11, INPUT_PULLUP);
  pinMode(centerButton12, INPUT_PULLUP);
  pinMode(centerButton13, INPUT_PULLUP);
  pinMode(centerButton14, INPUT_PULLUP);
  pinMode(centerButton15, INPUT_PULLUP);
  pinMode(centerButton16, INPUT_PULLUP);
  pinMode(centerButton17, INPUT_PULLUP);
  pinMode(centerButton18, INPUT_PULLUP);
  pinMode(centerButton19, INPUT_PULLUP);
  pinMode(centerButton20, INPUT_PULLUP);
  pinMode(centerButton21, INPUT_PULLUP);
  pinMode(centerButton22, INPUT_PULLUP);
  pinMode(centerButton23, INPUT_PULLUP);
  pinMode(centerButton24, INPUT_PULLUP);
  pinMode(centerButton25, INPUT_PULLUP);
  pinMode(centerButton26, INPUT_PULLUP);
  pinMode(centerButton27, INPUT_PULLUP);
  pinMode(centerButton28, INPUT_PULLUP);
  pinMode(centerButton29, INPUT_PULLUP);
  pinMode(centerButton30, INPUT_PULLUP);

  
  Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  knob1Axis = analogRead(knob1);
  knob1Axis = map(knob1Axis, 0 , 1023, 0, smoothing);
  Joystick.setRyAxis(knob1Axis);
  
  knob2Axis = analogRead(knob2);
  knob2Axis = map(knob2Axis, 0 , 1023, 0, smoothing);
  Joystick.setRzAxis(knob2Axis);
  
  flapsAxis = analogRead(flaps);
  flapsAxis = map(flapsAxis,  0, 1023, 0, smoothing);
  Joystick.setZAxis(flapsAxis);
  
  wingSweepAxis = analogRead(wingSweep);
  wingSweepAxis = map(wingSweepAxis, 0, 1023, 0, smoothing);
  Joystick.setRxAxis(wingSweepAxis);


  // Button Handling for F14 Panel

  int currentF14Button1State = !digitalRead(f14Button1);
  lastF14Button1 = setButtonState(currentF14Button1State, lastF14Button1, 30);
   
  int currentF14Button2State = !digitalRead(f14Button2);
  lastF14Button2 = setButtonState(currentF14Button2State, lastF14Button2, 31);

  int currentF14Button3State = !digitalRead(f14Button3);
  lastF14Button3 = setButtonState(currentF14Button3State, lastF14Button3, 32);

  int currentF14Button4State = !digitalRead(f14Button4);
  lastF14Button4 = setButtonState(currentF14Button4State, lastF14Button4, 33);

  int currentF14Button5State = !digitalRead(f14Button5);
  lastF14Button5 = setButtonState(currentF14Button5State, lastF14Button5, 34);

  int currentF14Button6State = !digitalRead(f14Button6);
  lastF14Button6 = setButtonState(currentF14Button6State, lastF14Button6, 35);

  int currentF14Button7State = !digitalRead(f14Button7);
  lastF14Button7 = setButtonState(currentF14Button7State, lastF14Button7, 36);

  int currentF14Button8State = !digitalRead(f14Button8);
  lastF14Button8 = setButtonState(currentF14Button8State, lastF14Button8, 37);

  int currentF14Button9State = !digitalRead(f14Button9);
  lastF14Button9 = setButtonState(currentF14Button9State, lastF14Button9, 38);

  // Button Handling for Center Panel
  int currentCenterButton1 = !digitalRead(centerButton1);
  lastCenterButton1 = setButtonState(currentCenterButton1, lastCenterButton1, 0);

  int currentCenterButton2 = !digitalRead(centerButton2);
  lastCenterButton2 = setButtonState(currentCenterButton2, lastCenterButton2, 1);
  
  int currentCenterButton3 = !digitalRead(centerButton3);
  lastCenterButton3 = setButtonState(currentCenterButton3, lastCenterButton3, 2);
  
  int currentCenterButton4 = !digitalRead(centerButton4);
  lastCenterButton4 = setButtonState(currentCenterButton4, lastCenterButton4, 3);
  
  int currentCenterButton5 = !digitalRead(centerButton5);
  lastCenterButton5 = setButtonState(currentCenterButton5, lastCenterButton5, 4);
  
  int currentCenterButton6 = !digitalRead(centerButton6);
  lastCenterButton6 = setButtonState(currentCenterButton6, lastCenterButton6, 5);
  
  int currentCenterButton7 = !digitalRead(centerButton7);
  lastCenterButton7 = setButtonState(currentCenterButton7, lastCenterButton7, 6);
  
  int currentCenterButton8 = !digitalRead(centerButton8);
  lastCenterButton8 = setButtonState(currentCenterButton8, lastCenterButton8, 7);
  
  int currentCenterButton9 = !digitalRead(centerButton9);
  lastCenterButton9 = setButtonState(currentCenterButton9, lastCenterButton9, 8);
  
  int currentCenterButton10 = !digitalRead(centerButton10);
  lastCenterButton10 = setButtonState(currentCenterButton10, lastCenterButton10, 9);
  
  int currentCenterButton11 = !digitalRead(centerButton11);
  lastCenterButton11 = setButtonState(currentCenterButton11, lastCenterButton11, 10);
  
  int currentCenterButton12 = !digitalRead(centerButton12);
  lastCenterButton12 = setButtonState(currentCenterButton12, lastCenterButton12, 11);
  
  int currentCenterButton13 = !digitalRead(centerButton13);
  lastCenterButton13 = setButtonState(currentCenterButton13, lastCenterButton13, 12);
  
  int currentCenterButton14 = !digitalRead(centerButton14);
  lastCenterButton14 = setButtonState(currentCenterButton14, lastCenterButton14, 13);
  
  int currentCenterButton15 = !digitalRead(centerButton15);
  lastCenterButton15 = setButtonState(currentCenterButton15, lastCenterButton15, 14);
  
  int currentCenterButton16 = !digitalRead(centerButton16);
  lastCenterButton16 = setButtonState(currentCenterButton16, lastCenterButton16, 15);
  
  int currentCenterButton17 = !digitalRead(centerButton17);
  lastCenterButton17 = setButtonState(currentCenterButton17, lastCenterButton17, 16);
  
  int currentCenterButton18 = !digitalRead(centerButton18);
  lastCenterButton18 = setButtonState(currentCenterButton18, lastCenterButton18, 17);
  
  int currentCenterButton19 = !digitalRead(centerButton19);
  lastCenterButton19 = setButtonState(currentCenterButton19, lastCenterButton19, 18);
  
  int currentCenterButton20 = !digitalRead(centerButton20);
  lastCenterButton20 = setButtonState(currentCenterButton20, lastCenterButton20, 19);
  
  int currentCenterButton21 = !digitalRead(centerButton21);
  lastCenterButton21 = setButtonState(currentCenterButton21, lastCenterButton21, 20);
  
  int currentCenterButton22 = !digitalRead(centerButton22);
  lastCenterButton22 = setButtonState(currentCenterButton22, lastCenterButton22, 21);
  
  int currentCenterButton23 = !digitalRead(centerButton23);
  lastCenterButton23 = setButtonState(currentCenterButton23, lastCenterButton23, 22);
  
  int currentCenterButton24 = !digitalRead(centerButton24);
  lastCenterButton24 = setButtonState(currentCenterButton24, lastCenterButton24, 23);
  
  int currentCenterButton25 = !digitalRead(centerButton25);
  lastCenterButton25 = setButtonState(currentCenterButton25, lastCenterButton25, 24);
  
  int currentCenterButton26 = !digitalRead(centerButton26);
  lastCenterButton26 = setButtonState(currentCenterButton26, lastCenterButton26, 25);
  
  int currentCenterButton27 = !digitalRead(centerButton27);
  lastCenterButton27 = setButtonState(currentCenterButton27, lastCenterButton27, 26);
  
  int currentCenterButton28 = !digitalRead(centerButton28);
  lastCenterButton28 = setButtonState(currentCenterButton28, lastCenterButton28, 27);
  
  int currentCenterButton29 = !digitalRead(centerButton29);
  lastCenterButton29 = setButtonState(currentCenterButton29, lastCenterButton29, 28);
  
  int currentCenterButton30 = !digitalRead(centerButton30);
  lastCenterButton30 = setButtonState(currentCenterButton30, lastCenterButton30, 29);
  Joystick.sendState();
  delay(20);
}
