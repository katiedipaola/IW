#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
#define ll long long

ll cmpfunc(const void *a, const void *b) { return (*(ll *)b - *(ll *)a); }

int max(int a, int b) { return (a > b) ? a : b; }

int main(void) {
  ll n, i, a, b;
  scanf("%lld %lld %lld", &n, &a, &b);
  ll h[n + 1];
  ll sum = 0;
  for (i = 1; i <= n; i++) {
    scanf("%lld", &h[i]);
    sum += h[i];
  }
  qsort(h + 1, n, sizeof(ll), cmpfunc);
  ll up = (ll)ceil(1.0 * h[1] / b);
  ll ans = 0;
  ans = (ll)1.0 * sum / (a - b + b * n);
  ll left = ans;
  ll right = up;
  ll cur = (left + right) / 2;
  while (left <= right && cur >= left && cur <= right) {
    ll count = 0;
    for (i = 1; i <= n; i++) {
      if (h[i] <= b * cur)
        continue;
      else {
        count += (ll)ceil(1.0 * (h[i] - b * cur) / (a - b));
        if (count > cur)
          break;
      }
    }
    if (count > cur) {
      left = cur + 1;
      cur = (left + right) / 2;
    } else if (count == cur || left >= right - 1) {
      if (left >= right - 1) {
        printf("%lld\n", cur);
        return 0;
      }
      while (count == cur) {
        cur--;
        count = 0;
        for (i = 1; i <= n; i++) {
          if (h[i] <= b * cur)
            continue;
          else {
            count += (ll)ceil(1.0 * (h[i] - b * cur) / (a - b));
            if (count > cur)
              break;
          }
        }
        if (count != cur) {
          printf("%lld\n", cur + 1);
          return 0;
        }
      }
      printf("%lld\n", cur - 1);
      return 0;
    } else {
      right = cur - 1;
      cur = (left + right) / 2;
    }
    // printf("%d %d %d %d\n",count,cur,left,right);
  }
  return 0;
}
