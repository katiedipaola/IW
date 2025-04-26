#include <stdio.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int i = 0;
  long long int ans = 0;
  for (i = 1; i <= k; i++) {
    if ((i + i) % k == 0) {
      long long int num = (n - i) / k + 1;
      ans = ans + num * num * num;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
