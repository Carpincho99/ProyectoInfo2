#include "../inc/allInc.h"

void moveAxis(uint8_t axis, uint8_t steps) {
  // uint8_t axies[4] = {X_STEP_PIN, Y_STEP_PIN, Z_STEP_PIN, S_PIN};
  // uint8_t axiesENB[4] = {XENB, YENB, ZENB, S_PIN};
  // uint8_t axiesDIR[4] = {X_DIR_PIN, Y_DIR_PIN, Z_DIR_PIN, S_PIN};

  // axiesENB[axis] |= _BV();

  PORTD &= ~_BV(PORTD6); /* Enciende LED */
  for (int i = 0; i < steps; i++) {
    PORTB |= _BV(PORTB5); /* Enciende LED */
    PORTD |= _BV(PORTD6); /* Enciende LED */
    _delay_ms(500);
    PORTB &= ~_BV(PORTB5); /* Enciende LED */
    PORTD &= ~_BV(PORTD6); /* Enciende LED */
    _delay_ms(500);
  }
}
