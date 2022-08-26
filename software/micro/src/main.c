#include <avr/sfr_defs.h>
#include <stdint.h>
#include <stdlib.h>
#include "../inc/allInc.h"

int main(void) {
  SetInOut();
  UART_init();
  UART_puts("OK\n");
  UCSR0B |= _BV(RXCIE0);
  sei();

  // gcLine gcComand = {0};
  // line =(char*) malloc(80*sizeof(char));

  for (;;) {
  }
  return 0;
}
