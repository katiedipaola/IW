#include <stdio.h>
#include <string.h>
int main() {
  int n, m, x, y, pos[22][22];
  int i, j, a, b, c, cnt;
  int l;
  char d[2];
  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break;
    memset(pos, 0, sizeof(pos));
    cnt = 0;
    for (i = 0; i < n; i++) {
      scanf("%d %d", &a, &b);
      pos[a][b] = 1;
    }
    x = 10;
    y = 10;
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
      scanf("%s%d", d, &l);
      for (j = 0; j < l; j++) {
        if (d[0] == 'N') {
          y++;
        } else if (d[0] == 'E') {
          x++;
        } else if (d[0] == 'S') {
          y--;
        } else if (d[0] == 'W') {
          x--;
        }
        if (pos[x][y] == 1) {
          cnt++;
          pos[x][y] = 0;
        }
      }
    }
    if (cnt == n) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}