#include <util/delay.h>
#include "../inc/allInc.h"

int main(void) {
  SetInOut();
  UART_init();
  pwm_init();
  sei();
	
  servo_set(0,180);

  char line[80];

  UART_puts("OK\n");
  for(;;){
    UART_gets(line);
    if(parse(line, execLine))
      UART_puts("[ERROR]\n");
    else
      UART_puts("OK\n");
  }

  return 0;
}
