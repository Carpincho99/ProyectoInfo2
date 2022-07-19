#ifndef UART_utils
#define UART_utils

void UART_init();
void UART_putc(unsigned char);
void UART_puts(char*);
unsigned char UART_getc(void);
char* UART_gets(char*, uint8_t);

#endif
