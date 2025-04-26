#include <stdio.h>
#include <stdlib.h>

int main() {

  int a, b, c, k;

  scanf("%d %d %d %d", &a, &b, &c, &k);

  if (abs(a - b) > 1e8) {
    printf("Unfair");
    return 0;
  }
  if (k % 2)
    printf("%d", b - a);
  else
    printf("%d", a - b);

  return 0;
}