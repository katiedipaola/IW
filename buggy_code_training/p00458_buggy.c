#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int ans = 0;

void brock(int ice[92][92], int x, int y, int dep) {
  ice[x][y] = 0;
  if (ice[x][y - 1] == 1) {
    brock(ice, x, y - 1, dep + 1);
  }
  if (ice[x][y + 1] == 1) {
    brock(ice, x, y + 1, dep + 1);
  }
  if (ice[x - 1][y] == 1) {
    brock(ice, x - 1, y, dep + 1);
  }
  if (ice[x + 1][y] == 1) {
    brock(ice, x + 1, y, dep + 1);
  }
  ice[x][y] = 1;
  if ((ice[x][y - 1] || ice[x][y + 1] || ice[x - 1][y] || ice[x + 1][y]) == 0) {
    if (dep + 1 > ans)
      ans = dep + 1;
  }
}

int main(void) {
  int m, n;
  int i, j;
  int ice[92][92];
  while (1) {
    scanf("%d", &m);
    scanf("%d", &n);
    if (m == 0 && n == 0)
      break;
    memset(ice, 0, sizeof(ice));
    for (j = 1; j <= n; j++) {
      for (i = 1; i <= m; i++) {
        scanf("%d", &ice[i][j]);
      }
    }
    for (j = 1; j <= n; j++) {
      for (i = 1; i <= m; i++) {
        if (ice[i][j] == 1)
          brock(ice, i, j, 0);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}