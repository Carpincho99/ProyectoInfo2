#include "../inc/mainIncludes.h"

int main(void) {
  int fd;

  fd = openTty();
  ttySet(fd, 115200);
  tcflush(fd, TCIOFLUSH);

  for (;;) {
    write(fd, "v", 1);
    tcdrain(fd);
    sleep(1);
  }

  close(fd);
  return 0;
}
