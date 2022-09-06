#include <avr/sfr_defs.h>
#include <stdint.h>
#include <util/delay.h>
#include "../inc/allInc.h"

#define msSteps 6

void doStepHorario(const uint8_t* axisPin) {
  for (uint8_t i = 0; i <= 3; i++) {
    PORTD |= _BV(axisPin[1]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[1]);
    PORTD |= _BV(axisPin[2]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[2]);
    PORTD |= _BV(axisPin[3]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[3]);
    PORTD |= _BV(axisPin[4]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[4]);
  }
}
void doStepAntiHorario(const uint8_t* axisPin) {
  for (uint8_t i = 0; i <= 3; i++) {
    PORTD |= _BV(axisPin[4]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[4]);
    PORTD |= _BV(axisPin[3]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[3]);
    PORTD |= _BV(axisPin[2]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[2]);
    PORTD |= _BV(axisPin[1]);
    _delay_ms(msSteps);
    PORTD &= ~_BV(axisPin[1]);
  }
}

void moveAxisRelative(uint8_t* axisPin, gcLine* gcCommand) {
    if (gcCommand->xyzServo[axisPin[0]] > 0) {
      doStepHorario(axisPin);
      gcCommand->xyzServo[axisPin[0]]--;
    } else {
      doStepAntiHorario(axisPin);
      gcCommand->xyzServo[axisPin[0]]++;
    }
  }

void execLine(gcLine* gcCommand) {
  uint8_t xAxisPin[5] = {0, X_IN1, X_IN2, X_IN3, X_IN4};
  uint8_t yAxisPin[5] = {1, Y_IN1, Y_IN2, Y_IN3, Y_IN4};
  uint8_t zAxisPin[5] = {2, Z_IN1, Z_IN2, Z_IN3, Z_IN4};

  // Realtive motion
  if (gcCommand->mode == 1) {
    while (1) {
      if (gcCommand->xyzServo[0] != 0) moveAxisRelative(xAxisPin, gcCommand);
      if (gcCommand->xyzServo[1] != 0) moveAxisRelative(yAxisPin, gcCommand);
      if (gcCommand->xyzServo[2] != 0) moveAxisRelative(zAxisPin, gcCommand);
    }
  }
}
