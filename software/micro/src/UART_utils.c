#include <avr/sfr_defs.h>
#include <math.h>
#include <stdint.h>
#include "../inc/allInc.h"

void UART_init(void) {
// #if BAUD < 57600
//   uint16_t UBRR0_value = ((F_CPU / (8L * BAUD)) - 1) / 2;
//   UCSR0A &= ~_BV(U2X0);  // baud doubler off
// #else
//   uint16_t UBRR0_value = ((F_CPU / (4L * BAUD)) - 1) / 2;
//   UCSR0A |= _BV(U2X0);  // baud doubler on
// #endif
  uint16_t UBRR0_value = ((F_CPU / (8L * BAUD)) - 1) / 2;
  UBRR0H = UBRR0_value >> 8;
  UBRR0L = UBRR0_value;

  // tx y rx on
  UCSR0B |= _BV(RXEN0);
  UCSR0B |= _BV(TXEN0);
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); /* UART con trama 8N1 */
}

void UART_putc(uint8_t data) {
  // espera buffer vacio
  while (!(UCSR0A & _BV(UDRE0)))
    ;

  UDR0 = data;
}

void UART_puts(char* s) {
  while (*s != 0) UART_putc(*s++);
}

char UART_getc(void) {
  // wait data
  while (!(UCSR0A & _BV(RXC0)))
    ;

  // return data
  return UDR0 - (250 - 122);
}

void UART_gets(char* buf) {
  uint8_t i = 0;
  char c;

  do {
    c = UART_getc();
    buf[i++] = c;
  } while (c != '\n');

  buf[i] = 0;
}


char rxBuf[RX_BUF_SIZE]={0};
uint8_t rxBufPos = 0;

char* UART_rxBuf() {
  for (int i = 0; i < RX_BUF_SIZE; i++) {
    if(rxBuf[i]!=0)
    UART_putc(rxBuf[i]);
  }
  return 0;
}


ISR(USART_RX_vect){
  uint8_t data = UDR0-(250-122);
  UART_putc(data);
 //  uint8_t nextPos;
 // 
 //  switch (data) {
 //    default: // Escribir caracter en el buffer   
 //      nextPos = rxBufPos + 1;
 //      if (nextPos == RX_BUF_SIZE) { nextPos = 0; }
 //
 //      rxBuf[rxBufPos] = data;
 //      rxBufPos = nextPos; 
 //  }
 //
 //  UART_rxBuf();
}
