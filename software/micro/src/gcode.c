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

uint8_t parse(char* line, gcLine *gcComand) {
  uint8_t n = 0;

  line = remove_white_spaces(line);

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
          case 0:
          case 1:
            gcComand->mode = MOTION_MODE_LINEAR;
            break;
          default:
            return 1;  // comando G no reconocido
            break;
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
