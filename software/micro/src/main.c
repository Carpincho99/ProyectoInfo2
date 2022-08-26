#include <avr/sfr_defs.h>
#include <stdint.h>
#include <stdlib.h>
#include "../inc/allInc.h"

int main(void) {
  SetInOut();
  UART_init();
  UART_puts("OK\n");
  char c[80];
  for(;;){
    UART_gets(c);
    UART_puts(c);
    
  }

  return 0;
}
