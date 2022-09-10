#ifndef gcode
#define gcode
#include <stdint.h>

int readNum(const char*, uint8_t*);
uint8_t parse(char*, void (*)(uint8_t, int16_t));
char* remove_white_spaces(char*);
void strToUpper(char* str);

#endif
