#include <stdio.h>

int main() {
  int n, h, w;
  scanf("%d", &n);
  scanf("%d", &h);
  scanf("%d", &w);

  printf("%d", (n - h) * (n - w));
  return 0;
}