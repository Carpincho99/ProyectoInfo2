#include <fcntl.h>
#include <termio.h>

struct termios tty;

int ttySet(int fd, int baudrate, struct termios* tty);
