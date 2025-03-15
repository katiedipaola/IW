#include <stdio.h>
int main() {
  int a, b, c, ans;
  scanf("%d%d", &a, &b);
  if (a == 100) {
    a++;
  }
  for (int i = 0; i < a; i++) {
    b *= 100;
  }
  printf("%d", b);
  return 0;
}
