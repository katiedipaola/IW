#include <stdio.h>
int main(void) {
  int num, count = 0;
  scanf("%d", &num);
  int i, t[num], x[num], y[num], dt, dx, dy;
  for (i = 0; i < num; i++) {
    scanf("%d%d%d", &t[i], &x[i], &y[i]);
  }
  dt = t[0];
  dx = x[0];
  dy = y[0];
  if (dx < 0)
    dx = -dx;
  if (dy < 0)
    dy = -dy;
  if (dx + dy > dt || (dt - (dx + dy)) % 2 == 1)
    count = 1;
  for (i = 1; i < num; i++) {
    dt = t[i] - t[i - 1];
    dx = x[i] - x[i - 1];
    dy = y[i] - y[i - 1];
    if (dx < 0)
      dx = -dx;
    if (dy < 0)
      dy = -dy;
    if (dx + dy > dt || (dt - (dx + dy)) % 2 == 1)
      count = 1;
  }
  if (count == 0)
    printf("Yes");
  else
    printf("No");
  return 0;
}