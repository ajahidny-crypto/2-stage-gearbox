// Spins the gearbox motor: ramps up, holds, ramps down, rests, repeats.
// Board: Arduino Uno (any board with a PWM pin should work)
//
// Wiring: the motor goes through a MOSFET, not straight to the pin.
//   Arduino pin 9 -> 220 ohm resistor -> MOSFET gate
//   10k resistor from the gate to GND, so the motor stays off at startup
//   MOSFET source -> GND (tie this to the Arduino GND too)
//   MOSFET drain -> motor wire 1
//   Motor wire 2 -> + of a 2x AA battery pack (about 3V)
//   Diode across the motor terminals, stripe on the + side
//   Battery pack - -> GND
// MOSFET: logic-level N-channel, like an IRLZ44N.

const int MOTOR_PIN = 9;        // PWM pin that drives the MOSFET gate

const int TOP_SPEED = 200;      // 0 to 255. Lower it for a slower spin.
const int RAMP_STEP = 5;        // speed change per step
const int RAMP_DELAY_MS = 40;   // time between steps
const long RUN_TIME_MS = 5000;  // time at top speed
const long REST_TIME_MS = 3000; // pause before the next run

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  analogWrite(MOTOR_PIN, 0);    // start stopped
  Serial.begin(9600);
  Serial.println("Gearbox motor test");
}

void loop() {
  // Ramp up slowly so the gears don't get a sudden jolt
  Serial.println("Ramping up");
  for (int speed = 0; speed <= TOP_SPEED; speed += RAMP_STEP) {
    analogWrite(MOTOR_PIN, speed);
    delay(RAMP_DELAY_MS);
  }

  Serial.println("Running");
  analogWrite(MOTOR_PIN, TOP_SPEED);
  delay(RUN_TIME_MS);

  // Ramp back down
  Serial.println("Ramping down");
  for (int speed = TOP_SPEED; speed >= 0; speed -= RAMP_STEP) {
    analogWrite(MOTOR_PIN, speed);
    delay(RAMP_DELAY_MS);
  }

  analogWrite(MOTOR_PIN, 0);
  Serial.println("Stopped");
  delay(REST_TIME_MS);
}
