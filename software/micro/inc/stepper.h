#ifndef stepper
#define stepper
#include "gcode.h"

void execLine(uint8_t, int16_t);
void moveAxisRelative(const uint8_t*, int16_t);
void doStepAntiHorario(const uint8_t*);
void doStepHorario(const uint8_t*);

#endif
