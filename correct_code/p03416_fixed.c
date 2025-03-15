#include <stdio.h>
int main() {
  int A, B, i, c, d, e, f, s = 0;
  scanf("%d %d", &A, &B);
  for (i = A; i <= B; i++) {
    c = i % 10;
    d = i / 10 % 10;
    e = i / 1000 % 10;
    f = i / 10000 % 10;
    if (c == f && d == e)
      s++;
  }
  printf("%d\n", s);
  return 0;
}
