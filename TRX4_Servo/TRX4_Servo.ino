#include <Servo.h>

//Front is Pin 3
//Rear is Pin 4

#include "PWM.hpp"

PWM InputServo(2); // Setup pin 2 for PWM
int frontServoOpen = 1992;
int frontServoLocked = 992;
int backServoOpen = 992;
int backServoLocked = 1992;
int pulse;
Servo Front;
Servo Back;


void setup() {
    Serial.begin(115200); // Serial for debug
    InputServo.begin(true); // PWM on pin 2 reading PWM HIGH duration
    pinMode(LED_BUILTIN, OUTPUT);
    Front.attach(3);
    Back.attach(4);
}

void loop() {
  InputServo.getValue();
  pulse = InputServo.getValue();
  delay(25);
  digitalWrite(LED_BUILTIN, HIGH);
  
  if (pulse <= 1300){
    Front.writeMicroseconds(frontServoOpen);
    Back.writeMicroseconds(backServoOpen);
  }
  if (pulse > 1300 && pulse < 1700){
    Front.writeMicroseconds(frontServoLocked);
    Back.writeMicroseconds(backServoOpen);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (pulse >= 1700){
    Front.writeMicroseconds(frontServoLocked);
    Back.writeMicroseconds(backServoLocked);
    delay(20);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
