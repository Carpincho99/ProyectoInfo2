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

int main(int argc, char *argv[]) {
  int fd;

  fd = openTty(PORT);
  ttySet(fd, 115200);
  tcflush(fd, TCIOFLUSH);

  if(argc > 1){
    FILE* fdComands;
    char fdComandsCadena[80] = {0};
    fdComands = fopen(argv[1], "r");
    char buf[80] = {0};
    read(fd, &buf, 8);
    tcdrain(fd);
    while (1) {
      if (feof(fdComands)) 
        fseek(fdComands, 0, SEEK_SET);
      if(!strncmp(buf, "OK\n", 8)){
        printf("[MICRO] %s", buf);
        tcdrain(fd);
        if(fgets(fdComandsCadena, 78, fdComands)==NULL)
          continue;
        fdComandsCadena[79] = '\n';
        printf("%s", fdComandsCadena);
        write(fd, fdComandsCadena, bitsUntilc(fdComandsCadena, '\n'));
        tcdrain(fd);
        sleep(3);
      }else{
        printf("[ERROR]");
        return EXIT_FAILURE;
      }
    }
    fclose(fdComands);
  }

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
