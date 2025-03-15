#include <stdio.h>
int main(void) {
  int i, n, sum, x;
  scanf("%d", &n);
  while (n != 0) {
    sum = 0;
    for (i = 0; i < n / 4; i++) {
      scanf("%d", &x);
      sum += x;
    }
    printf("%d\n", sum);
    scanf("%d", &n);
  }
  return 0;
}
