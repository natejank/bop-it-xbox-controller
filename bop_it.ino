/**
 * Copyright 2022 Nathan Jankowski
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <PicoGamepad.h>

#define PICO_SERIAL_BAUD 115200
#define POLLING_RATE 100

#define CENTER_PIN 16
#define TWIST_PIN 17
#define PULL_PIN 18
#define SPIN_PIN 19
#define FLICK_PIN 20
#define TOGGLE_PIN 21

/** XBOX CONTROLLER BINDINGS
 * A: 1
 * B: 2
 * X: 3
 * Y: 4
 * Left bumper: 5
 * Right bumper: 6
 * SELECT: 7
 * START: 8
 * Left joystick click: 9
 * Right joystick click: 10
 * 
 */

#define CENTER_BUTTON 1
#define TWIST_BUTTON 2
#define PULL_BUTTON 3
#define SPIN_BUTTON 4
#define FLICK_BUTTON 5
#define TOGGLE_BUTTON 6

struct Bop_It {
  bool center;
  bool twist;
  bool pull;
  bool spin;
  bool flick;
  bool toggle;
};

Bop_It bop_it;
PicoGamepad gamepad;


int input_values;
int last_update = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(PICO_SERIAL_BAUD);
  pinMode(LED_BUILTIN, OUTPUT);

  // setup buttons
  pinMode(CENTER_PIN, INPUT_PULLUP);
  pinMode(TWIST_PIN, INPUT_PULLUP);
  pinMode(PULL_PIN, INPUT_PULLUP);
  pinMode(SPIN_PIN, INPUT_PULLUP);
  pinMode(FLICK_PIN, INPUT_PULLUP);
  pinMode(TOGGLE_PIN, INPUT_PULLUP);

  bop_it = {false, false, false, false, false, false};

  Serial.println("Bop-It xbox controller initialization complete!");
}

void loop() {
  // put your main code here, to run repeatedly:

  // check if actions have been taken since the last update
  bop_it.center = (bop_it.center) ? true : !digitalRead(CENTER_PIN);
  bop_it.twist = (bop_it.twist) ? true : !digitalRead(TWIST_PIN);
  bop_it.pull = (bop_it.pull) ? true : !digitalRead(PULL_PIN);
  bop_it.spin = (bop_it.spin) ? true : !digitalRead(SPIN_PIN);
  bop_it.flick = (bop_it.flick) ? true : !digitalRead(FLICK_PIN);
  bop_it.toggle = (bop_it.toggle) ? true : !digitalRead(TOGGLE_PIN);

  // update after interval
  if(millis() - last_update > POLLING_RATE) {
    last_update += POLLING_RATE;
    gamepad.SetButton(CENTER_BUTTON, bop_it.center);
    gamepad.SetButton(TWIST_BUTTON, bop_it.twist);
    gamepad.SetButton(PULL_BUTTON, bop_it.pull);
    gamepad.SetButton(SPIN_BUTTON, bop_it.spin);
    gamepad.SetButton(FLICK_BUTTON, bop_it.flick);
    gamepad.SetButton(TOGGLE_BUTTON, bop_it.toggle);

    gamepad.send_update();
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // flash the led for funsies
    bop_it = {false, false, false, false, false, false};
  }
}
