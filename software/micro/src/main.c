#include <stdint.h>
#include <stdlib.h>
#include "../inc/allInc.h"

int main(void) {
  SetInOut();
  UART_init();
  UART_puts("OK\n");

  gcLine gcComand = {0};
  for (;;) {

    char* buf;
    buf = (char*)calloc(80, 8);
    UART_puts("Waiting for command...\n");
    UART_gets(buf);
    UART_puts("command recived\n");
    if (parse(buf, &gcComand)) {
      UART_puts("ERROR parse");
    }

    for (int i = 0; i < gcComand.xyzServo[0]; i++) {
      PORTB |= _BV(PORTB5); /* Enciende LED */
      PORTD |= _BV(PORTD6); /* Enciende LED */
      _delay_ms(100);
      PORTB &= ~_BV(PORTB5); /* Apaga LED */
      PORTD &= ~_BV(PORTD6); /* Apaga LED */
      _delay_ms(100);
    }

    // // c = UART_getc();
  }
  return 0;
}
