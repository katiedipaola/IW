#include <stdio.h>

int main(void) {
  int w, h, i, j, k, a[100], b[100];
  char grid[100][101];
  scanf("%d %d", &h, &w);
  getchar();
  for (i = 0; i < h; i++) {
    fgets(grid[i], w + 2, stdin);
  }
  for (i = 0; i < h; i++) {
    a[i] = 1;
    for (j = 0; j < w; j++) {
      if (grid[i][j] == '#') {
        a[i] = 0;
        break;
      }
    }
  }
  for (i = 0; i < w; i++) {
    b[i] = 1;
    for (j = 0; j < h; j++) {
      if (grid[j][i] == '#') {
        b[i] = 0;
        break;
      }
    }
  }
  for (i = 0; i < h; i++) {
    if (a[i] == 0) {
      for (j = 0; j < w; j++) {
        if (b[j] == 0)
          putchar(grid[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
