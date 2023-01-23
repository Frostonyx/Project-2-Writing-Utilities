#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 2048

void main(int argc, char *argv[]) {
  int fd, n;
  char buf[BUFSIZE];

  if (argc != 2) {
    perror("Usage: readfile <file>");
    exit(1);
  }

  if ((fd = open(argv[1], O_RDONLY)) < 0) {
    perror("open error");
    exit(1);
  }

  while ((n = read(fd, buf, BUFSIZE)) > 0) {
    if (write(1, buf, n) != n) {
      perror("write error");
      exit(1);
    }
  }

  if (n < 0) {
    perror("read error");
    exit(1);
  }

  close(fd);
  exit(0);
}
