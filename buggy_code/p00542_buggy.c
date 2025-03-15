#include <stdio.h>
int main() {
  int a = 0, i = 0, sum = 0, n = 0, m = 100;
  for (i = 0; i < 4; i++) {
    scanf("%d", &a);
    sum += a;
    if (a < m) {
      m = a;
    }
  }
  sum -= m;
  m = 0;
  for (i = 0; i < 2; i++) {
    scanf("%d", &a);
    sum += a;
    if (a < m) {
      m = a;
    }
  }
  sum -= m;
  printf("%d\n", sum);
  return 0;
}