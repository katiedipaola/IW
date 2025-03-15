#include <stdio.h>

int main(void) {

  long int a, b, c, k, n, max;

  scanf("%ld%ld%ld", &a, &b, &c);
  scanf("%ld", &k);

  if (a <= b)
    max = b;
  else
    max = a;

  if (max <= c)
    max = c;

  n = max;

  for (int i = 0; i < k; i++)
    n *= 2;

  printf("%ld", a + b + c + n - max);
  return 0;
}