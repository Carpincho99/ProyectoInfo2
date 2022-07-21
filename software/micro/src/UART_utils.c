#include <math.h>
#include <stdint.h>
#include "../inc/allInc.h"

void UART_init(void) {
#if BAUD_RATE < 57600
  uint16_t UBRR0_value = ((F_CPU / (8L * BAUD)) - 1) / 2;
  UCSR0A &= ~_BV(U2X0);  // baud doubler off
#else
  uint16_t UBRR0_value = ((F_CPU / (4L * BAUD)) - 1) / 2;
  UCSR0A |= _BV(U2X0);  // baud doubler on
#endif
  UBRR0H = UBRR0_value >> 8;
  UBRR0L = UBRR0_value;

  // enable rx and tx
  UCSR0B |= 1 << RXEN0;
  UCSR0B |= 1 << TXEN0;
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); /* UART con trama 8N1 */
  UCSR0B |= _BV(RXEN0);               /* Habilita el receptor */
}

void UART_putc(unsigned char data) {
  // wait for transmit buffer to be empty
  while (!(UCSR0A & _BV(UDRE0)))
    ;

  UDR0 = data;
}

void UART_puts(char* s) {
  while (*s > 0) UART_putc(*s++);
}

unsigned char UART_getc(void) {
  // wait for data
  while (!(UCSR0A & (1 << RXC0)))
    ;

  // return data
  return UDR0;
}

char* UART_gets(char* buf, uint8_t n) {
  uint8_t bufIdx = 0;
  char c;

  do {
    c = UART_getc();
    buf[bufIdx++] = c;
  } while ((bufIdx < n) && (c != '\r'));

  buf[bufIdx] = 0;
  return buf;
}
