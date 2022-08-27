#include <avr/sfr_defs.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/allInc.h"

int main(void) {
  SetInOut();
  UART_init();
  UART_puts("OK\n");
  char line[80];
  gcLine gcCommand = {0};
  // gcLine gcStatus = {0};

  for(;;){
    UART_gets(line);
    parse(line, &gcCommand);
    moveAxis(1, gcCommand.xyzServo[0]) ;
  }

  return 0;
}
