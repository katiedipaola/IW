#include <stdio.h>

long long comb(long long n, long long r) {
  static long long c[50][50] = {};
  if (r == 0 || r == n)
    return c[n][r] = 1;
  if (r == 1 || r == n - 1)
    return c[n][r] = n;
  if (c[n][r] != 0)
    return c[n][r];
  if (c[n][n - r] != 0)
    return c[n][r] = c[n][n - r];

  return c[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}

int main() {
  long long i, a, b, ans = 0;
  int n, p, t;
  char s[100];

  scanf(" %d %d", &n, &p);

  a = b = 0;
  for (i = 0; i < n; i++) {
    scanf(" %d", &t);
    t % 2 ? a++ : b++;
    // printf("[%d (%lld,%lld)] ", t, a, b);
  }

  if (p) {
    for (i = 1; i <= a; i += 2) {
      ans += comb(a, i);
      // printf("comb(%lld,%lld):%lld ", a, i, comb(a, i));
    }
  } else {
    for (i = 2; i <= a; i += 2) {
      ans += comb(a, i);
      // printf("comb(%lld,%lld):%lld ", a, i, comb(a, i));
    }
  }
  // printf("ans: %lld (%lld, %lld) ", ans, a, b);
  ans *= 1 << b;
  sprintf(s, "%lld", ans);
  puts(s);
  return 0;
}
