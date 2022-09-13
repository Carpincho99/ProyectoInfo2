#include "../inc/allInc.h"

#define msSteps 5
void primerStep(const uint8_t *axisPin){
  PORTD &= ~_BV(axisPin[0]) || ~_BV(axisPin[1]) || ~_BV(axisPin[2]) || ~_BV(axisPin[3]);
  PORTD |= _BV(axisPin[0]);
}

void segundoStep(const uint8_t *axisPin){
  PORTD &= ~_BV(axisPin[0]) || ~_BV(axisPin[1]) || ~_BV(axisPin[2]) || ~_BV(axisPin[3]);
  PORTD |= _BV(axisPin[1]);
}

void tercerStep(const uint8_t *axisPin){
  PORTD &= ~_BV(axisPin[0]) || ~_BV(axisPin[1]) || ~_BV(axisPin[2]) || ~_BV(axisPin[3]);
  PORTD |= _BV(axisPin[2]);
}

void cuartoStep(const uint8_t *axisPin){
  PORTD &= ~_BV(axisPin[0]) || ~_BV(axisPin[1]) || ~_BV(axisPin[2]) || ~_BV(axisPin[3]);
  PORTD |= _BV(axisPin[3]);
}

void (*doStepHorario[4]) (const uint8_t*) = {primerStep, segundoStep,tercerStep, cuartoStep};

void moveAxisRelative(const uint8_t* axisPin, int16_t value) {
  static uint8_t nStep;
  if (value > 0) {
    nStep = 0;
    while (value) {
      (*doStepHorario[nStep])(axisPin);
      value--;
      if(++nStep == 4)
        nStep = 0;
      _delay_ms(msSteps);
    }
  } else {
    nStep = 4;
    while (value) {
      (*doStepHorario[nStep-1])(axisPin);
      value++;
      if(--nStep == 0)
        nStep = 4;
      _delay_ms(msSteps);
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
