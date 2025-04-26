#include <stdio.h>

int main() {
  long n, x, a[100], i, j, t;

  scanf("%ld %ld", &n, &x);
  for (i = 0; i < n; i++)
    scanf("%ld", &a[i]);
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++)
      if (a[i] > a[j]) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
    x -= a[i];
    if (x < 0)
      break;
  }
  if (x == 0 || i == 0)
    printf("%ld\n", i + 1);
  else
    printf("%ld\n", i);
  return 0;
}
