#include <stdio.h>

int main() {
  int w;

  while (1) {
    scanf("%d", &w);
    if (w == -1)
      break;
    if (w <= 10)
      printf("3130\n");
    else if (w <= 20)
      printf("%d\n", 3130 - 125 * (w - 10));
    else if (w <= 30)
      printf("%d\n", 1880 - 140 * (w - 20));
    else
      printf("%d\n", 480 - 160 * (w - 30));
  }
  return 0;
}