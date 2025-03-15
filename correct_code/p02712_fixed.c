#include <math.h>
#include <stdio.h>
int main() {
  long long int n, i, t;
  long long int sum = 0;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    t = i;
    if (t % 3 == 0 || t % 5 == 0) {
      t = 0;
    }
    sum = sum + t;
  }

  printf("%lld", sum);
}
