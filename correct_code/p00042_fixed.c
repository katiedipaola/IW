#include <stdio.h>

int main(void) {
  int w = 0;
  int n = 0;
  int i = 0, j = 0;
  int val = 0;
  int maxval = 0;
  int maxg = 0;
  int g = 0;
  int count = 0;

  while (1) {
    scanf("%d", &w);
    if (w == 0) {
      break;
    }
    scanf("%d", &n);

    int bag[w + 1];

    for (i = 0; i <= w; i++) {
      bag[i] = 0;
    }

    for (i = 0; i < n; i++) {
      scanf("%d,%d", &val, &g);
      for (j = w; j >= 0; j--) {
        if (bag[j] != 0 && g + j <= w) {
          if (bag[j] + val > bag[g + j]) {
            bag[g + j] = bag[j] + val;
          }
        }
        if (j == 0 && g <= w) {
          if (val > bag[g]) {
            bag[g] = val;
          }
        }
      }
    }
    for (i = 0; i <= w; i++) {
      if (bag[i] > maxval) {
        maxval = bag[i];
        maxg = i;
      }
    }
    count++;
    printf("Case %d:\n", count);
    printf("%d\n%d\n", maxval, maxg);
    g = 0;
    maxg = 0;
    maxval = 0;
  }
  return 0;
}