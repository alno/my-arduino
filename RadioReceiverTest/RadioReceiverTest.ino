void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int pin = 0; pin < 4; ++ pin) {
    Serial.print(analogRead(pin));
    Serial.print(" ");
  }
  Serial.println();

  delay(2000);
}
