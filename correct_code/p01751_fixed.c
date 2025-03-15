#include <stdio.h>

int main(void) {
  int a, b, c, sign, sign1 = 0, time, t, sum;
  scanf("%d %d %d", &a, &b, &c);
  if (!(60 % (a + b)))
    sign1 = 1;
  for (time = 0, t = 0, sign = 0;; sign = 1 - sign) {
    if (!sign) {
      time += a;
    } else {
      time += b;
    }
    if (time >= c && time - a <= c && !sign) {
      sum = t * 60 + c;
      break;
    }
    if (time >= 60) {
      t++;
      time -= 60;
      if (time >= c && !sign) {
        sum = t * 60 + c;
        break;
      }
      if (sign1 || (!time && sign)) {
        sum = -1;
        break;
      }
    }
  }
  printf("%d\n", sum);
  return 0;
}