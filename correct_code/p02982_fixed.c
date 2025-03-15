#include <stdio.h>
int main(void) {
  int n, d;
  int x[10][10];
  float k = 0.0;
  int c = 0;
  int sei;
  int i, j, p = 1;
  int s;
  scanf("%d %d", &n, &d);
  for (i = 0; i < n; i++) {
    for (j = 0; j < d; j++) {
      scanf("%d", &x[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (p = i + 1; p < n; p++) {
      for (j = 0; j < d; j++) {
        k += (x[i][j] - x[p][j]) * (x[i][j] - x[p][j]);
      }
      for (sei = 1; sei <= 126; sei++) {
        s = sei * sei;
        if (k == s) {
          c++;
          break;
        }
      }
      k = 0;
    }
  }
  printf("%d", c);
  return 0;
}