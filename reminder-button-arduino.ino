const byte LED_HIGH_PIN = 0;
const byte LED_LOW_PIN = 1;
const byte SWITCH_SIGNAL_PIN = 3;
const byte SWITCH_TEST_PIN = 4;

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
  pinMode(SWITCH_TEST_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(SWITCH_TEST_PIN)) {
    /* still pulled high */
    digitalWrite(LED_HIGH_PIN, LOW);
  } else {
    /* pulled low by switch */
    digitalWrite(LED_HIGH_PIN, HIGH);
  }
  delay(25);
}
