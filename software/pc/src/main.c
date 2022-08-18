#include <stdio.h>
#include "../inc/mainIncludes.h"

int main(void) {
  int fd;
  char c[3] = {0};

  fd = openTty();
  ttySet(fd, 115200);
  tcflush(fd, TCIOFLUSH);

  for (;;) {
    // write(fd, "v", 1);
    read(fd, &c, 3);
    printf("%s", c);
    tcdrain(fd);
    sleep(1);
  }

  close(fd);
  return 0;
}
