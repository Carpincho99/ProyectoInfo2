#include <stdint.h>
#include <stdlib.h>
#include "../inc/allInc.h"

char* remove_white_spaces(char* str) {
  int i = 0, j = 0;
  while (str[i]) {
    if (str[i] != ' ') str[j++] = str[i];
    i++;
  }
  str[j] = '\0';
  return str;
}

int readNum(const char* line, uint8_t* n) {
  uint8_t i = 0;
  float value;
  char* valueStr;

  valueStr = (char*) calloc(10, sizeof(char));
  
  if (line[*n] == '-'|| line[*n] == '+') {
    valueStr[0] = line[*n];
    (*n)++;
    i++;
  }
  
  while((line[*n] >= '0' && line[*n] <= '9')|| line[*n] == '.'){
    valueStr[i] = line[*n];
    (*n)++;
    i++;
  }

  value = atoi(valueStr);
  return value;
}

uint8_t parse(char* line, gcLine *gcComand) {
  uint8_t n = 0;

  line = remove_white_spaces(line);

  while (line[n] != 0) {
    char letter;
    int value;

    letter = line[n];

    if ((letter < 'A') || (letter > 'Z')) return 1;  // Se esperaba una letra

    n++;

    if (line[n] != '-' && line[n] != '+' && (line[n] < '0' || line[n] > '9'))
      return 1;  // Se esperaba un numero

    value = readNum(line, &n);


    switch (letter) {
      case 'G':
        switch (value) {
          case 0:
          case 1:
            gcComand->mode = MOTION_MODE_ABS;
            break;
          case 91:
            gcComand->mode = MOTION_MODE_RELATIVE;
            break;
          default:
            return 1;  // comando G no reconocido
        }
        break;
      case 'X':
        gcComand->xyzServo[0] = value;
        break;
      case 'Y':
        gcComand->xyzServo[1] = value;
        break;
      case 'Z':
        gcComand->xyzServo[2] = value;
        break;
      case 'S':
        gcComand->xyzServo[3] = value;
        break;
      default:
        return 1;  // Comando no reconocido
    }
  }

  return 0;  // OK
}
