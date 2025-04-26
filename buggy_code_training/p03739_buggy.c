#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))

int main() {
  int n;
  scanf("%d", &n);

  long long a[n];
  for (int i = 0; i < n; i++)
    scanf("%lld", a + i);

  long long initial_plus = max(-1 - a[0], 0);
  long long initial_minus = max(1 + a[0], 0);

  long long sum = 0;

  //初項を正にした場合
  sum = max(a[0], 1);
  for (int i = 1; i < n; i++) {
    if ((sum + a[i]) * sum >= 0ll) {
      if (sum < 0ll) {
        initial_plus += 1 - sum - a[i];
        sum = 1;
      } else {
        initial_plus += sum + a[i] + 1;
        sum = -1;
      }
    } else {
      sum += a[i];
    }
  }

  //初項を負にした場合
  sum = min(a[0], -1);
  for (int i = 1; i < n; i++) {
    if ((sum + a[i]) * sum >= 0ll) {
      if (sum < 0ll) {
        initial_minus += 1 - sum - a[i];
        sum = 1;
      } else {
        initial_minus += sum + a[i] + 1;
        sum = -1;
      }
    } else {
      sum += a[i];
    }
  }

  printf("%lld\n", min(initial_plus, initial_minus));

  return 0;
}