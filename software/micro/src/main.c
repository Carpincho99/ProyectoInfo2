#include "../inc/allInc.h"

int main(void) {
  SetInOut();
  UART_init();
  UART_puts("OK\n");

  char line[80];

  for(;;){
    UART_gets(line);
    if(parse(line, execLine)){
      UART_puts("[ERROR]");
    }
  }

  return 0;
}
