#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int random() {
  int output;
  int file = open("/dev/random", O_RDONLY);
  read(file, &output, sizeof(int));
  close(file);
  return output;
}

int main() {
  int n = random();
  printf("%d\n", n);
  return 0;
}
