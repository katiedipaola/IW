#include <stdio.h>
#include <stdlib.h>

int main(void) {
  long long n, a, b;

  scanf("%lld %lld %lld", &n, &a, &b);

  if ((b - a) % 2 == 0) {
    printf("%lld", (b - a) / 2);
  } else {
    if (a - 1 < n - b) {
      printf("%lld", a + (b - a - 1) / 2);
    } else {
      printf("%lld", n - b + 1 + (b - a - 1) / 2);
    }
  }

  return 0;
}