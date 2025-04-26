#include <math.h>
#include <stdio.h>

int main(void) {

  int N, K, i, j, c;
  long double x = 0;

  scanf("%d %d", &N, &K);

  for (j = 1; j <= N; j++) {
    i = j;
    c = 0;
    while (i < K) {
      i += i;
      c++;
    }
    x = x + (1 / (N * pow(2, c)));
  }
  printf("%.20lf\n", x);

  return 0;
}
