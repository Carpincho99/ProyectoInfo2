#ifndef __STDINT_H_
#include <stdint.h>
#endif

#ifndef stepper
#define stepper

void execLine(uint8_t, int16_t);
void moveAxisRelative(const uint8_t*, int16_t);
void doStepAntiHorario(const uint8_t*);
void doStepHorario(const uint8_t*);

#endif
