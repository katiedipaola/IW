#include <stdio.h>

int main(void) {
  int i, j, k, n, min, temp, r[101], m[100][100];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &r[i], &r[i + 1]);
    m[i][i] = 0;
  }

  for (i = 1; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      for (k = j; k < j + i; k++) {
        temp = m[j][k] + m[k + 1][j + i] + r[j] * r[k + 1] * r[j + i + 1];
        if (k == j || min > temp)
          min = temp;
      }
      m[j][j + i] = min;
    }
  }

  printf("%d\n", m[0][n - 1]);

  return 0;
}