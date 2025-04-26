#include <stdio.h>
int main(void) {

  int a, b, c, x;

  while (1) {
    scanf("%d %d %d", &a, &b, &c);
    x = a + b;
    if (a == -1 && b == -1 && c == -1)
      break;
    if (a == -1 || b == -1)
      printf("F\n");
    if (x >= 80)
      printf("A\n");
    if (65 <= x && x < 80)
      printf("B\n");
    if (50 <= x && x < 65)
      printf("C\n");
    if (30 <= x && x < 50) {
      if (c >= 50)
        printf("C\n");
      else
        printf("D\n");
    }
    if (x < 30)
      printf("F\n");
  }
}