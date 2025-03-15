#include <inttypes.h>
#include <stdio.h>

int main() {
  long long int i, n, num;
  int digit;
  int min = 12;

  scanf("%I64d", &n);

  i = 1;
  while (i * i <= n) {
    if (n % i == 0) {
      num = n / i;
      digit = 0;
      while (num != 0) {
        num /= 10;
        digit++;
      }

      if (min > digit)
        min = digit;
    }
    i++;
  }

  printf("%d\n", min);

  return 0;
}