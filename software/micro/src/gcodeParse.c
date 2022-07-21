#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/allInc.h"

typedef struct gcLine {
  uint8_t command;
  uint8_t xyz[3];
  float f;  // feadrate
} gcLine;

float readNum(const char* line, uint8_t* n) {
  float value;
  uint8_t counter = 0;
  value = atof(&line[*n]);
  while (value != 0) {
    value = value / 10;
    counter++;
  }
  *n += counter;
  return value;
}

uint8_t gcExec(gcLine gcComand){
  return 0;
}

uint8_t parse(const char* line) {
  gcLine gcComand = {0};
  uint8_t n = 0;

  while (line[n] != 0) {
    char letter;
    uint8_t value;

    letter = line[n];

    if ((letter < 'A') || (letter > 'Z')) return 1;  // Se esperaba una letra

    n++;

    if (line[n] != '-' && line[n] != '+' && (line[n] < '0' || line[n] > '9'))
      return 1;  // Se esperaba un numero
    value = readNum(line, &n);

    n++;

    switch (letter) {
      case 'G':
        switch (value) {
          default:
            return 1;  //comando G no reconocido
            break;
        }
        break;
      case 'X':
        gcComand.xyz[0] = value;
        break;
      case 'Y':
        gcComand.xyz[1] = value;
        break;
      case 'Z':
        gcComand.xyz[2] = value;
        break;
      default:
        return 1;  // Comando no reconocido
    }

    gcExec(gcComand);
  }

  return 0;  // OK
}
