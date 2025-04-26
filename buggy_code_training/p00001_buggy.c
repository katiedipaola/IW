#include <stdio.h>

int main(void) {
  int num[10];
  int x, a, b, i;

  for (i = 0; i < 9; i++) {
    scanf("%d", &num[i]);
  }

  for (a = 0; a < 8; a++) {
    for (b = a + 1; b < 8; b++) {
      if (num[a] < num[b]) {
        x = num[a];
        num[a] = num[b];
        num[b] = x;
      }
    }
  }

  printf("%d\n%d\n%d\n", num[0], num[1], num[2]);

  return 0;
}