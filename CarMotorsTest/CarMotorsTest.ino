#include <AFMotor.h>

AF_DCMotor rot(2);
AF_DCMotor mot(3);

void setup() {
  Serial.begin(9600);
  Serial.println("Motor test!");

  mot.setSpeed(255);
  mot.run(RELEASE);

  rot.setSpeed(255);
  rot.run(RELEASE);
}

void loop() {
  Serial.println("tick");

  mot.run(FORWARD);
  delay(2000);
  mot.run(BACKWARD);
  delay(2000);
  mot.run(RELEASE);

  delay(3000);

  rot.run(FORWARD);
  delay(2000);
  rot.run(BACKWARD);
  delay(2000);
  rot.run(RELEASE);

  delay(3000);
}
