#include <avr/sfr_defs.h>
#include <math.h>
#include <stdint.h>
#include "../inc/allInc.h"

void UART_init(void) {
#if BAUD < 57600
  uint16_t UBRR0_value = ((F_CPU / (8L * BAUD)) - 1) / 2;
  UCSR0A &= ~_BV(U2X0);  // baud doubler off
#else
  uint16_t UBRR0_value = ((F_CPU / (4L * BAUD)) - 1) / 2;
  UCSR0A |= _BV(U2X0);  // baud doubler on
#endif
  UBRR0H = (uint8_t) UBRR0_value >> 8;
  UBRR0L = (uint8_t) UBRR0_value;

  // tx y rx on
  UCSR0B |= _BV(RXEN0);
  UCSR0B |= _BV(TXEN0);
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); /* UART con trama 8N1 */
}

void UART_putc(uint8_t data) {
  // espera buffer vacio
  while (!(UCSR0A & _BV(UDRE0)));

  UDR0 = data;
}

void UART_puts(char* s) {
  while (*s) UART_putc(*s++);
}

char UART_getc(void) {
  // wait data
  while (!(UCSR0A & _BV(RXC0)))
    ;

  // return data
  return UDR0;
}

void UART_gets(char* buf) {
  uint8_t i = 0;
  char c;

  do{
    c = UART_getc();
    buf[i++] = c;
  }while (c != '\n') ;

  buf[i] = 0;
}
