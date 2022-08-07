#ifndef UART_utils
#define UART_utils

void UART_init();
void UART_putc(unsigned char);
void UART_puts(char*);
char UART_getc(void);
void UART_gets(char*);

#endif
