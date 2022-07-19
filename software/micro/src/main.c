
#include "mainIncludes.h"

int main(void) {
  DDRD |= _BV(DDD5);
  DDRD |= _BV(DDD7);
  //UART_init();
  while (1) {
    // UART_putc('a');
    PORTB |= _BV(PORTB5); /* Enciende LED */
    PORTD |= _BV(PORTD7); /* Enciende LED */
    _delay_ms(100);
    PORTB &= ~_BV(PORTB5); /* Apaga LED */
    PORTD &= ~_BV(PORTD7); /* Apaga LED */
    _delay_ms(100);
  }
  return 0;
}
