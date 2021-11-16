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

  int file = open("cheese", O_CREAT | O_WRONLY, 0600);
  write(file, &randomwans, sizeof(int[10]));
  close(file);

  int randomtwos[10];
  file = open("cheese", O_RDONLY);
  read(file, &randomtwos, sizeof(int[10]));
  close(file);
  
  for (int i = 0; i < 10; i ++) {
    printf("%d ", randomtwos[i]);
  }
  printf("\n");

  return 0;
}
