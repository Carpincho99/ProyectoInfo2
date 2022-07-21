#include <stdint.h>
#include "../inc/allInc.h"

int main(void) {
  DDRD |= _BV(DDD5);
  DDRD |= _BV(DDD6);
  UART_init();

  while (1) {
    // c = UART_getc();
    PORTB |= _BV(PORTB5); /* Enciende LED */
    PORTD |= _BV(PORTD6); /* Enciende LED */
    _delay_ms(100);
    PORTB &= ~_BV(PORTB5); /* Apaga LED */
    PORTD &= ~_BV(PORTD6); /* Apaga LED */
    _delay_ms(100);
    UART_putc('a');
  }
  return 0;
}
