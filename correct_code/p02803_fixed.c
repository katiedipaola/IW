#include <stdbool.h>
#include <stdio.h>
#define ll long long
char s[22][22];
int v[22][22];
int h, w;

void dfs(int y, int x, int a) {
  if (x < 0 || x >= w || y < 0 || y >= h || v[y][x] <= a || s[y][x] == '#')
    return;
  v[y][x] = a;
  dfs(y + 1, x, a + 1);
  dfs(y, x + 1, a + 1);
  dfs(y - 1, x, a + 1);
  dfs(y, x - 1, a + 1);
  return;
}

int main() {
  int i, j, si, sj, gi, gj, ans = 0;
  scanf("%d %d", &h, &w);
  for (i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  for (si = 0; si < h; si++) {
    for (sj = 0; sj < w; sj++) {
      if (s[si][sj] == '.') {
        for (i = 0; i < h; i++)
          for (j = 0; j < w; j++)
            v[i][j] = 1000000009;
        dfs(si, sj, 0);
        for (gi = 0; gi < h; gi++)
          for (gj = 0; gj < w; gj++)
            if (s[gi][gj] == '.')
              ans = ans < v[gi][gj] ? v[gi][gj] : ans;
      }
    }
  }
  printf("%d", ans);
  return 0;
}