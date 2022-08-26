#include <avr/sfr_defs.h>
#include <stdint.h>
#include <stdlib.h>
#include "../inc/allInc.h"

int main(void) {
  SetInOut();
  UART_init();
  UART_puts("OK\n");
  char line[80];
  char c[10];
  gcLine gcCommand = {0};
  for(;;){
    UART_gets(line);
    parse(line, &gcCommand);
    itoa(gcCommand.mode+1, c, 10);
    UART_puts(c);
  }

  return 0;
}
