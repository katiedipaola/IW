#include <stdio.h>

int main() {
  int n, k, a;

  scanf("%d", &k);
  a = 7;
  for (n = 1; a % k > 0 && n < k; n++)
    a = (a * 10 + 7) % k;
  if (n < k)
    printf("%d\n", n);
  else
    puts("-1");
  return 0;
}
