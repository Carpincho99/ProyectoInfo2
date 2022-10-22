#ifndef __STDINT_H_
#include <stdint.h>
#endif

#ifndef stepper
#define stepper

void execLine(uint8_t, int16_t);
void moveAxisRelative(volatile uint8_t*, const uint8_t*, int16_t);
void doStepAntiHorario(volatile uint8_t*, const uint8_t*);
// void doStepHorario(const uint8_t*);

#endif
