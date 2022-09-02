#include <avr/sfr_defs.h>
#include <stdint.h>
#include <util/delay.h>
#include "../inc/allInc.h"

#define msSteps 20

void doStep(const uint8_t* axisPin) {
  uint8_t stepPatron[4][4] = {
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1},
    {1,0,0,1},
  };
    for (uint8_t i = 0; i <= 3; i++) {
      _delay_ms(msSteps);
    }
}

void execLine(gcLine* gcCommand) {
  uint8_t xAxisPin[4] = {X_IN1, X_IN2, X_IN3, X_IN4};
  // uint8_t yAxisPin[4] = {Y_IN1, Y_IN2, Y_IN3, Y_IN4};
  // uint8_t zAxisPin[4] = {Z_IN1, Z_IN2, Z_IN3, Z_IN4};

  while (1) {
    doStep(xAxisPin);
  }
}
