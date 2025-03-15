#include <math.h>
#include <stdio.h>
#define num 2 * 100000 + 10

int main(void) {
  int N, D, i, C = 0;
  int x[num], y[num];
  scanf("%d %d", &N, &D);

  for (i = 0; i < N; i++) {
    scanf("%d%d", &x[i], &y[i]);
    if (D >= sqrt((x[i] * x[i]) + (y[i] * y[i]))) {
      C++;
    }
  }
  printf("%d", C);
}