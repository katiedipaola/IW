#include <stdio.h>
int main(void) {

  int a, b, c, d, p;
  int ma1, ma2;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &p);

  if (p > c) {
    ma1 = b + p * d;
  } else {
    ma1 = b;
  }
  ma2 = a * p;

  if (ma1 < ma2) {
    printf("%d\n", ma1);
  } else {
    printf("%d\n", ma2);
  }

  return 0;
}