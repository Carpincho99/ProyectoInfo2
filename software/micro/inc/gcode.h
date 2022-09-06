#ifndef gcode
#define gcode
#include <stdint.h>

typedef struct gcLine {
  uint8_t mode;
  int xyzServo[4];
} gcLine;

int readNum(const char*, uint8_t*);
uint8_t gcExec(const gcLine*);
uint8_t parse(char*, gcLine*);
char* remove_white_spaces(char*);

#endif
