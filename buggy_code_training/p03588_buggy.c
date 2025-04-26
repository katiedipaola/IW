#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int a, b, i, N, mina = 0, minb;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d %d", &a, &b);
    if (mina > a) {
      mina = a;
      minb = b;
    }
  }
  printf("%d", mina + minb);
  return 0;
}
