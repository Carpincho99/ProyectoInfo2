#include "UART_utils.h"
#include "mainIncludes.h"

int main(void) {
  UART_init();
  UART_putc('a');
  return 0;
}
