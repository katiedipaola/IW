#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int int64;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > (0) ? (a) : -(a))

void run(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k == 1) {
    printf("%lld\n", (int64)n * n * n);
    return;
  }
  int64 d = n / k;
  int64 e = (k % 2 == 0 ? (n + k / 2) / k : 0);
  int64 ans = d * d * d + e * e * e;
  printf("%lld\n", ans);
}

int main(void) {
  run();
  return 0;
}
