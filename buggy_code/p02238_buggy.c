#include <stdio.h>

void visit(int);
int G[101][101];
int d[101], f[101], color[101], time, n;

void visit(int v) {
  int i;
  color[v] = 1;
  d[v] = ++time;
  for (i = 0; i < n; i++) {
    if (G[v][i] == 1) {
      if (color[i] == 0)
        visit(i);
    }
  }
  color[v] = 2;
  f[v] = ++time;
}

int main() {

  int i, j, v1, v2, m;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    color[i] = 0;
    for (j = 0; j < n; j++) {
      G[i][j] = 0;
    }
  }

  time = 0;

  for (i = 0; i < n; i++) {
    scanf("%d%d", &v1, &m);
    for (j = 0; j < m; j++) {
      scanf("%d", &v2);
      G[v1 - 1][v2 - 1] = 1;
    }
  }

  for (i = 0; i < n; i++) {
    if (color[i] == 0)
      visit(i);
  }

  for (i = 0; i < n; i++) {
    printf("%d%d%d\n", i + 1, d[i], f[i]);
  }
  return 0;
}