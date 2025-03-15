#include <stdio.h>
int main(void) {
  int n, m, i, j;
  int a[100][100], b[100], c[100];

  scanf("%d %d\n", &n, &m);

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (i = 0; i < n; i++) {
    scanf("%d\n", &b[i]);
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      c[i] += a[i][j] * b[j];
    }
    printf("%d\n", c[i]);
  }

  return 0;
}
