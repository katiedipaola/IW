#include <stdio.h>

int main() {
  int i, j, u, k, n, v, A[101][101] = {};

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &u);
    scanf("%d", &k);
    for (j = 1; j <= k; j++) {
      scanf("%d", &v);
      A[u][v] = 1;
    }
  }

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (!j)
        printf(" ");
      printf("%d", A[i][j]);
    }
    printf("\n");
  }
  return 0;
}