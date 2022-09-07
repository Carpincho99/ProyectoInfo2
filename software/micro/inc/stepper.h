#ifndef stepper
#define stepper
#include "gcode.h"

void execLine(uint8_t, int8_t);
void moveAxisRelative(const uint8_t*, int8_t);
void doStepAntiHorario(const uint8_t*);
void doStepHorario(const uint8_t*);

#endif
