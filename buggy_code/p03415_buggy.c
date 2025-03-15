#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char c[15];

int main(void) {
  for (int i = 0; i < 15; i++)
    c[i] = getchar();

  printf("%c%c%c", c[0], c[6], c[12]);

  return 0;
}