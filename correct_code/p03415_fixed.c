#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char c[12];

int main(void) {
  for (int i = 0; i < 12; i++)
    c[i] = getchar();

  printf("%c%c%c", c[0], c[5], c[10]);

  return 0;
}