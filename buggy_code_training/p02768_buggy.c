#include <stdio.h>

#define MD 1000000007

int power(int a, int b) {
  int p;

  if (b == 0)
    return 1;
  p = power(a, b / 2);
  p = (long long)p * p % MD;
  if (b % 2)
    p = (long long)p * a % MD;
  return p;
}

int choose(int n, int k) {
  return k == 0
             ? 1
             : (long long)choose(n - 1, k - 1) * n % MD * power(k, MD - 2) % MD;
}

int main() {
  int n, a, b, ans;

  scanf("%d%d%d", &n, &a, &b);
  ans = power(2, n) - 1 - choose(n, a) - choose(n, b);
  if (ans < 0)
    ans += MD;
  printf("%d\n", ans);
  return 0;
}
