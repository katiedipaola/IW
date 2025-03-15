#include <stdio.h>

int main(void) {
  int n, i, f = 1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    f = i * f;
  }
  printf("%d\n", f);
}