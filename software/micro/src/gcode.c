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

void strToUpper(char* str){
  const char Offset = 'a' - 'A';
  while (*str){
    *str = (*str >= 'a' && *str <= 'z') ? *str - Offset : *str;
    str++;
  }
}

int readNum(const char* line, uint8_t* n) {
  uint8_t i = 0;
  float value;
  char* valueStr;
  uint8_t dotflag = 0;

  valueStr = (char*) calloc(10, sizeof(char));
  
  if (line[*n] == '-'|| line[*n] == '+') {
    valueStr[0] = line[*n];
    (*n)++;
    i++;
  }
  
  while((line[*n] >= '0' && line[*n] <= '9')|| line[*n] == '.'){

    if(line[*n] == '.'){
      if(dotflag == 0){
        valueStr[i] = line[*n];
        (*n)++;
        dotflag++;
        continue;
      }else{
        return 0;
      }
    }

      
    valueStr[i] = line[*n];
    (*n)++;
    i++;
  }

  value = atoi(valueStr);
  return (int16_t) value;
}

uint8_t parse(char* line, void (*execLine)(uint8_t, int16_t)) {
  uint8_t n = 0;

  line = remove_white_spaces(line);
  strToUpper(line);

  char letter;
  int value;

  letter = line[n];

  if ((letter < 'A') || (letter > 'Z')) 
    return 1;  // Se esperaba una letra

  n++;

  if (line[n] != '-' && line[n] != '+' && (line[n] < '0' || line[n] > '9'))
    return 1;  // Se esperaba un numero

  value = readNum(line, &n);

  execLine(letter, value);

  return 0;  // OK
}
