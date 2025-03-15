#include <stdio.h>

int main() {
  int i, j, a, b;
  char c[3][12];
  scanf("%s", c[0]);
  scanf("%s", c[1]);
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%s", c[2]);
  for (i = 0; i < 12; i++) {
    if (c[0][i] != c[2][i]) {
      b--;
      break;
    }
    if (c[0][i] == 0) {
      a--;
      break;
    }
  }
  printf("%d ", a);
  printf("%d", b);
  return 0;
}