#include <stdio.h>

int main() {
  int a[40] = {0}, i, n;
  for (i = 0; i < 28; i++) {
    scanf("%d", &n);
    a[n] = 1;
  }
  for (i = 1; i <= 30; i++) {
    if (a[i] == 0)
      printf("%d\n", i);
  }
  return 0;
}