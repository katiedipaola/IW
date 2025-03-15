#include <stdio.h>
int main(void) {
  int n;
  unsigned long long a = -1, b = 2;
  scanf("%d", &n);
  while (n-- > 0) {
    b = a + b;
    a = b - a;
  }
  printf("%d\n", b);
  return 0;
}
