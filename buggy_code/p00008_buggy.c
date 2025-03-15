#include <stdio.h>

int main(void) {

  int ans = 0;
  int a, b, c, d, n;

  while (scanf("%d", &n) != EOF) {
    for (a = 0; a <= 9; a++) {
      for (b = 0; b <= 9; b++) {
        for (c = 0; c <= 9; c++) {
          for (d = 0; d <= 9; d++) {
            if (a + b + c + d == n) {
              ans++;
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}