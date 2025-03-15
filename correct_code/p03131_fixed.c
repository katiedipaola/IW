#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  long long int k, a, b, i, ans;

  scanf("%ld %ld %ld", &k, &a, &b);

  if (a >= b - 2 || k - a <= 0)
    ans = 1 + k;
  else {
    if ((k - a) % 2 == 0)
      ans = (k - a) / 2 * b - (k - a - 2) / 2 * a + 1;

    else
      ans = (k - a + 1) / 2 * b - (k - a - 1) / 2 * a;
  }
  printf("%ld", ans);
}