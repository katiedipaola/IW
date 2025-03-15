#include <stdio.h>
int main() {
  int x[4];
  for (int i = 0; i < 4; i++)
    scanf("%d", &x[i]);
  int x3, y3, x4, y4;
  x3 = x[2] + (x[3] - x[1]) * -1;
  y3 = x[3] + x[2] - x[0];
  x4 = x3 + (y3 - x[3]) * -1;
  y4 = y3 + x3 - x[2];
  printf("%d %d %d %d\n", x3, y3, x4, y4);
}