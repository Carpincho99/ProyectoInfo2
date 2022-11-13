#include <avr/sfr_defs.h>
#include "../inc/allInc.h"

#define msSteps 5
void primerStep(volatile uint8_t* port, const uint8_t *axisPin){
  *port &= ~_BV(axisPin[1]);
  *port &= (~_BV(axisPin[1]) || ~_BV(axisPin[2]) || ~_BV(axisPin[3]) || ~_BV(axisPin[4]));
  *port |= _BV(axisPin[1]);
  *port |= _BV(axisPin[2]);
}

void segundoStep(volatile uint8_t* port, const uint8_t *axisPin){
  *port &= ~_BV(axisPin[1]);
  *port &= (~_BV(axisPin[1]) || ~_BV(axisPin[2]) || ~_BV(axisPin[3]) || ~_BV(axisPin[4]));
  *port |= _BV(axisPin[2]);
  *port |= _BV(axisPin[3]);
}

void tercerStep(volatile uint8_t* port,const uint8_t *axisPin){
  *port &= ~_BV(axisPin[1]);
  *port &= (~_BV(axisPin[1]) || ~_BV(axisPin[2]) || ~_BV(axisPin[3]) || ~_BV(axisPin[4]));
  *port |= _BV(axisPin[3]);
  *port |= _BV(axisPin[4]);
}

void cuartoStep(volatile uint8_t* port,const uint8_t *axisPin){
  *port &= ~_BV(axisPin[1]);
  *port &= (~_BV(axisPin[1]) || ~_BV(axisPin[2]) || ~_BV(axisPin[3]) || ~_BV(axisPin[4]));
  *port |= _BV(axisPin[4]);
  *port |= _BV(axisPin[1]);
}

void (*doStepHorario[4]) (volatile uint8_t* ,const uint8_t*) = {primerStep, segundoStep,tercerStep, cuartoStep};

void moveAxisRelative(volatile uint8_t* port,const uint8_t* axisPin, int16_t value) {
  static uint8_t nStep;
  if (value > 0) {
    nStep = 0;
    while (value) {
      (*doStepHorario[nStep])(port,axisPin);
      value--;
      if(++nStep == 4)
        nStep = 0;
      _delay_ms(msSteps);
    }
  } else {
    nStep = 4;
    while (value) {
      (*doStepHorario[nStep-1])(port,axisPin);
      value++;
      if(--nStep == 0)
        nStep = 4;
      _delay_ms(msSteps);
    }
  }
}

void execLine(uint8_t axi, int16_t value) {
 const uint8_t xAxisPin[5] = {PORTD, X_IN1, X_IN2, X_IN3, X_IN4};
 const uint8_t yAxisPin[5] = {PORTB, Y_IN1, Y_IN2, Y_IN3, Y_IN4};
 const uint8_t zAxisPin[5] = {PORTC, Z_IN1, Z_IN2, Z_IN3, Z_IN4};
 static uint8_t s = 0; //1 open - 0 close


  // Realtive motion
  switch (axi) {
    case 'X':
      moveAxisRelative(&PORTC, xAxisPin, value);
      break;
    case 'Y':
      moveAxisRelative(&PORTB, yAxisPin, value);
      break;
    case 'Z':
      moveAxisRelative(&PORTD, zAxisPin, value);
      break;
    case 'S':
      if(s){
        servo_set(0, 180); //Cerrar
        s=0;
      }else{
        servo_set(80, 180); //Cerrar
        s=1;
      }
      break;
  }
}
