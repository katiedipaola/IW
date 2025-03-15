#include <stdio.h>

int main(void) {
  int L, i;

  long double L3;

  scanf("%d", &L);

  L3 = (long double)L / 3;

  printf("%.12Lf\n", L3 * L3 * L3);

  return 0;
}