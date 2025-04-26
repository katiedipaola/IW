#include <stdio.h>

int main(void) {
  int L, i;

  double L3;

  scanf("%d", &L);

  L3 = L / 3;

  printf("%.12f\n", L3 * L3 * L3);

  return 0;
}