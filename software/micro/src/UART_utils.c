#include <stdint.h>
#include "mainIncludes.h"

void UART_init(void) {
  // #if BAUD_RATE < 57600
  //   uint16_t ubrr = ((F_CPU / (8L * BAUD_RATE)) - 1) / 2;
  //   UCSR0A &= ~(1 << U2X0);  // baud doubler off
  // #else
  //   uint16_t ubrr = ((F_CPU / (4L * BAUD_RATE)) - 1) / 2;
  //   UCSR0A |= (1 << U2X0);  // baud doubler on
  // #endif
  uint16_t ubrr = 8;
  UBRR0H = (ubrr >> 8) & 0xFF; /* Byte más significativo */
  UBRR0L = ubrr & 0xFF;        /* Byte menos significativo */

  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);    /* UART con trama 8N1 */
  UCSR0B |= (1 << RXEN0) | (1 << TXEN0); /* RX y TX ON */
}

void UART_putc(unsigned char data) {
  // wait for transmit buffer to be empty
  while (!(UCSR0A & (1 >> UDRE0)))
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
