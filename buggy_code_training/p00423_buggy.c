#include <stdio.h>

int main(void) {
  int n;
  int i;
  int a, b;
  int a_score, b_score;

  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    a_score = b_score = 0;

    for (i = 0; i < n; i++) {
      scanf("%d %d", &a, &b);

      if (a > b) {
        a_score += a + b;
      } else if (a < b) {
        b_score += a + b;
      } else {
        a_score = a;
        b_score = b;
      }
    }

    printf("%d %d\n", a_score, b_score);
  }

  return (0);
}