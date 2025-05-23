#include <math.h>
#include <stdio.h>

int main() {
  int n, i, N;
  double x;
  int ans;

  scanf("%d", &n);
  ans = n;
  x = sqrt(n);

  i = 2;
  while (i <= x) {
    if (n % i == 0) {
      while (n % i == 0) {
        n = n / i;
      }
      ans = ans * (i - 1) / i;
    }
    i++;
  }

  if (n != 1)
    ans = ans * (n - 1) / n;
  printf("%d", ans);
  printf("\n");

  return 0;
}
