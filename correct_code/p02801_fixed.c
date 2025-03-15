#include <stdio.h>

int main(void) {
  printf("%c\n", fgetc(stdin) + 1);
  return 0;
}