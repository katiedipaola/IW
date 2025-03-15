#include <stdio.h>

int main(void) {
  int d, h, i;

  while (EOF != scanf("%d", &d)) {

    h = 0;

    for (i = 0; i < 600 / d; i++) {
      h += d * i * d * i;
    }

    printf("%d\n", h * d);
  }

  return 0;
}