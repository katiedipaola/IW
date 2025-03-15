#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll int GCD(ll int x, ll int y) { return y == 0 ? x : GCD(y, x % y); }

int main(void) {
  int n, i;
  scanf("%d", &n);
  ll int t, ans, t1;
  scanf("%lld", &t);
  ans = t;
  for (i = 1; i < n; i++) {
    scanf("%lld", &t1);
    ans = t / GCD(t, t1) * t1;
  }
  printf("%lld", ans);
  return 0;
}