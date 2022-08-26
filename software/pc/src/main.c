#include <stdio.h>
#include "../inc/mainIncludes.h"

int main(void) {
  int fd;
  char c[4] = {0};

  fd = openTty();
  ttySet(fd, 115200);
  tcflush(fd, TCIOFLUSH);

  // for (;;) {
    // write(fd, "v", 1);
    read(fd, &c, 3);
    printf("MICRO %s", c);
    tcdrain(fd);
    write(fd, "Ho\n", 1);
    tcdrain(fd);
    read(fd, &c, 4);
    printf("MICRO %s", c);
    sleep(1);
  // }

  close(fd);
  return 0;
}
