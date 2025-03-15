#include <stdio.h>

int main(void) {
  int N;
  int k;
  int max;
  int n;
  int i;

  while (1) {
    scanf("%d", &N);
    if (N == 0) {
      break;
    }

    n = 0;
    max = 0;
    for (i = 0; i < N; i++) {
      scanf("%d", &k);

      if (k > 0) {
        n++;
      }
      if (k > max) {
        max = k;
      }
    }

    if (N == 1 && max >= 2) {
      printf("2\n");
    } else if (max <= 1) {
      printf("NA\n");
    } else {
      printf("%d\n", n + 1);
    }
  }

  return (0);
}