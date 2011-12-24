#include <URM37.h>

URM37 urm(&Serial1);

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(13, OUTPUT);
}

void loop() {
  int d = urm.getDistance();

  if (d < 30) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  Serial.print("Distance: ");
  Serial.println(d);

  Serial.print("Temp: ");
  Serial.println(urm.getTemperature());

  delay(1000);
}
