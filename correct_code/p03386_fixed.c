#include <stdio.h>
int main() {
  int A, B, K, i, j, k;
  scanf("%d%d%d", &A, &B, &K);
  if (K * 2 >= B - A + 1) {
    for (i = A; i <= B; i++) {
      printf("%d\n", i);
    }
  } else {
    for (j = A; j <= A + K - 1; j++) {
      printf("%d\n", j);
    }
    for (k = B - K + 1; k <= B; k++) {
      printf("%d\n", k);
    }
  }
}