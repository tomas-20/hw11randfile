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
  int randomwans[10];
  for (int i = 0; i < 10; i ++) {
    randomwans[i] = random();
  }
  for (int i = 0; i < 10; i ++) {
    printf("%d ", randomwans[i]);
  }
  printf("\n");
  return 0;
}
