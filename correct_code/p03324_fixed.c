#include <stdio.h>
int main() {
  int a, b, c, ans;
  scanf("%d%d", &a, &b);
  if (b == 100) {
    b++;
  }
  for (int i = 0; i < a; i++) {
    b *= 100;
  }
  printf("%d", b);
  return 0;
}
