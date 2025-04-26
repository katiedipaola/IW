#include <stdio.h>

int main(void) {
  int n;
  int h, m;
  int i, j;
  int bus[24][60] = {0};
  int c;

  for (i = 0; i < 2; i++) {
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
      scanf("%d %d", &h, &m);
      bus[h][m] = 1;
    }
  }

  c = 0;
  for (h = 0; h < 24; h++) {
    for (m = 0; m < 60; m++) {
      if (bus[h][m]) {
        if (c == 0) {
          printf(" ");
        }
        c = 1;
        printf("%d:%02d", h, m);
      }
    }
  }
  printf("\n");

  return (0);
}