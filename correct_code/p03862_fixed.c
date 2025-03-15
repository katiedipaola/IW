#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, N;
  long long x, a, prev, v = 0;
  scanf("%d %lld", &N, &x);
  scanf("%lld", &prev);

  if (prev > x) {
    v = prev - x;
    prev = x;
  }

  for (i = 1; i < N; i++) {
    scanf("%lld", &a);
    if (prev + a > x) {
      v += prev + a - x;
      prev = x - prev;
    } else {
      prev = a;
    }
  }
  printf("%lld\n", v);
  return 0;
}