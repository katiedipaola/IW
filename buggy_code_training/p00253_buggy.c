
#include <stdio.h>
int main(void) {
  int n, h[101];
  int i, j, k;
  int sa[101], b[101];
  int flg;

  scanf("%d", &n);
  while (n != 0) {
    for (i = 0; i < n + 1; i++) {
      scanf("%d", &h[i]);
    }
    for (i = 0; i < n + 1; i++) {
      k = 0;
      for (j = 0; j < n + 1; j++) {
        if (i != j) {
          b[k] = h[j];
          k++;
        }
      }
      for (j = 0; j < n - 1; j++) {
        sa[j] = b[j + 1] - b[j];
      }
      flg = 0;
      for (j = 0; j < n - 2; j++) {
        if (sa[j] != sa[j + 1]) {
          flg = 1;
        }
      }
      if (flg == 0) {
        printf("%d\n", h[i]);
      }
    }
    scanf("%d", &n);
  }
  return 0;
}