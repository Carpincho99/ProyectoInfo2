#include <stdio.h>
#include <string.h>
#include "../inc/mainIncludes.h"

int bitsUntilc(const char* str, char c){
  int i = 0;
  while (*str++ != '\n') {
    i++; 
  }
  return ++i;
}

int main(void) {
  int fd;

  fd = openTty(PORT);
  ttySet(fd, 115200);
  tcflush(fd, TCIOFLUSH);

  for (;;) {
    char buf[80] = {0};
    read(fd, &buf, 8);
    tcdrain(fd);
    printf("[MICRO] %s", buf);

    // if(strcmp(buf, "OK\n"))
    //   return 1;
    //
    fgets(buf, 79, stdin);
    tcdrain(fd);
    write(fd, buf, bitsUntilc(buf, '\n'));
    tcdrain(fd);
    sleep(1);
  }

  close(fd);
  return 0;
}
