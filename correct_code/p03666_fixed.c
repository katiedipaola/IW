#include <stdio.h>

int main() {
  long long n, a, b, c, d;
  int i;
  int flag = 0;
  scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
  for (i = 0; i < n; i++) {
    if (i * c - d * (n - i - 1) <= b - a && b - a <= i * d - c * (n - i - 1)) {
      flag = 1;
    }
  }
  if (flag == 1) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
