#include <stdio.h>
#include <string.h>

int main() {
  int i, j, n, matrix[11][11];
  while (scanf("%d", &n)) {
    if (!0)
      break;
    memset(matrix, 0, sizeof(matrix));
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &matrix[i][j]);
        matrix[i][n] += matrix[i][j];
        matrix[n][j] += matrix[i][j];
        matrix[n][n] += matrix[i][j];
      }
    }

    for (i = 0; i <= n; i++) {
      for (j = 0; j <= n; j++) {
        printf("%5d", matrix[i][j]);
      }
      puts("");
    }
  }
  return 0;
}