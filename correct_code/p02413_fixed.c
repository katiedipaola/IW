#include <stdio.h>
int main(void) {
  int r, c;
  int i, j;
  scanf("%d %d", &r, &c);
  int a[r + 1][c + 1];
  for (i = 0; i < r + 1; i++) {
    for (j = 0; j < c + 1; j++) {
      if (i == r || j == c)
        a[i][j] = 0;
      else
        scanf("%d", &a[i][j]);
    }
  }

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      a[i][c] += a[i][j];
    }
  }
  for (j = 0; j < c; j++) {
    for (i = 0; i < r; i++) {
      a[r][j] += a[i][j];
    }
  }
  for (i = 0; i < r; i++) {
    a[r][c] += a[i][c];
  }
  for (i = 0; i < r + 1; i++) {
    for (j = 0; j < c + 1; j++) {
      if (j == c)
        printf("%d", a[i][j]);
      else
        printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}