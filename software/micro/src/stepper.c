#include "../inc/allInc.h"

#define msSteps 5

void doStepHorario(const uint8_t* axisPin) {
  for (uint8_t i = 0; i <= 3; i++) {
    PORTD |= _BV(axisPin[0]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[0]);
    PORTD |= _BV(axisPin[1]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[1]);
    PORTD |= _BV(axisPin[2]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[2]);
    PORTD |= _BV(axisPin[3]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[3]);
  }
}
void doStepAntiHorario(const uint8_t* axisPin) {
  for (uint8_t i = 0; i <= 3; i++) {
    PORTD |= _BV(axisPin[3]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[3]);
    PORTD |= _BV(axisPin[2]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[2]);
    PORTD |= _BV(axisPin[1]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[1]);
    PORTD |= _BV(axisPin[0]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[0]);
  }
}

void moveAxisRelative(const uint8_t* axisPin, int16_t value) {
  if (value > 0) {
    while (value) {
      doStepHorario(axisPin);
      value--;
    }
  } else {
    while (value) {
      doStepAntiHorario(axisPin);
      value++;
    }
  }
}

void execLine(uint8_t axi, int16_t value) {
 const uint8_t xAxisPin[4] = {X_IN1, X_IN2, X_IN3, X_IN4};
 const uint8_t yAxisPin[4] = {Y_IN1, Y_IN2, Y_IN3, Y_IN4};
 const uint8_t zAxisPin[4] = {Z_IN1, Z_IN2, Z_IN3, Z_IN4};

  // Realtive motion
  switch (axi) {
    case 'X':
      moveAxisRelative(xAxisPin, value);
      break;
    case 'Y':
      moveAxisRelative(yAxisPin, value);
      break;
    case 'Z':
      moveAxisRelative(zAxisPin, value);
      break;
  }
}
