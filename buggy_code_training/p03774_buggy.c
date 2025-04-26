#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int N, M, i, j, a, b, gen, gend, it;
  int xn[50], yn[50];
  int xm[50], ym[50];
  scanf("%d %d", &N, &M);
  for (i = 0; i < N; i++) {
    scanf("%d %d", &a, &b);
    xn[i] = a;
    yn[i] = b;
  }
  for (i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    xm[i] = a;
    ym[i] = b;
  }
  for (i = 0; i < N; i++) {
    gen = 999;
    gend = 123456789;
    for (j = 0; j < M; j++) {
      it = abs(xm[j] - xn[i]) + abs(ym[j] - yn[i]);
      if (gend > it) {
        gend = it;
        gen = j;
      }
    }
    printf("%d\n", gen + 1);
  }
  return 0;
}