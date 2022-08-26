#include <stdint.h>
#include <stdlib.h>
#include "../inc/allInc.h"

int main(void) {
  SetInOut();
  UART_init();
  UART_puts("OK\n");

  // gcLine gcComand = {0};
  char line[80];

  for (;;) {
    line[0]=UART_getc();
    UART_putc(line[0]);
  }
  return 0;
}
