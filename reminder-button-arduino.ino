#include <Snooze.h>

SnoozeDigital digital;

const byte LED_HIGH_PIN = 0;
const byte LED_LOW_PIN = 1;
const byte SWITCH_SIGNAL_PIN = 3;
const byte SWITCH_TEST_PIN = 4;

volatile byte state = HIGH;

SnoozeBlock config(digital);

void setup() {
  /* switch led high */
  pinMode(LED_HIGH_PIN, OUTPUT);
  digitalWrite(LED_HIGH_PIN, LOW);

  /* switch led low */
  pinMode(LED_LOW_PIN, OUTPUT);
  digitalWrite(LED_LOW_PIN, LOW);

  /* switch signal */
  pinMode(SWITCH_SIGNAL_PIN, OUTPUT);
  digitalWrite(SWITCH_SIGNAL_PIN, LOW);

  /* switch test */
  digital.pinMode(SWITCH_TEST_PIN, INPUT_PULLUP, FALLING);
}

void loop() {
  /* Go into deep sleep. Wake on interrupt. */
  Snooze.deepSleep(config);

  /* Toggle the LED */
  state = !state;
  digitalWrite(LED_HIGH_PIN, state);

  /* Debounce */
  delay(300);
}
