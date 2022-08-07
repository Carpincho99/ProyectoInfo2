#ifndef gcode
#define gcode
#include <stdint.h>

typedef struct gcLine {
  uint8_t mode;
  uint8_t xyzServo[4];
  float f;  // feadrate
} gcLine;

float readNum(const char*, uint8_t*);
uint8_t gcExec(const gcLine*);
uint8_t parse(char*, gcLine*);

#endif
