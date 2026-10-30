// motor spin test for the gearbox
// arduino uno. the motor runs through a mosfet, not straight off the pin
// (it pulls way more current than a pin can give)
//
// wiring:
//   pin 9 -> 220 ohm resistor -> mosfet gate
//   10k resistor from gate to gnd
//   mosfet source -> gnd (and the arduino gnd)
//   mosfet drain -> one motor wire
//   other motor wire -> + on the 2xAA pack (about 3V)
//   diode across the motor, stripe toward the +
//   battery - -> gnd
// using a logic level mosfet (IRLZ44N)

int motorPin = 9;
int topSpeed = 200;   // max is 255, go lower if its too fast

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // speed up slowly so the gears dont get jolted
  Serial.println("speeding up");
  for (int s = 0; s <= topSpeed; s += 5) {
    analogWrite(motorPin, s);
    delay(40);
  }

  // hold for 5 sec
  Serial.println("running");
  delay(5000);

  // slow back down
  Serial.println("slowing down");
  for (int s = topSpeed; s >= 0; s -= 5) {
    analogWrite(motorPin, s);
    delay(40);
  }

  analogWrite(motorPin, 0);
  Serial.println("stopped");
  delay(3000);   // rest before going again
}
