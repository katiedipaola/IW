#include <stdio.h>
#define INF 100000000
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int M[MAX][MAX], d[MAX];

void dijkstra() {

  int i, u, v, mincost = 0;
  int color[MAX], pi[MAX];

  for (i = 0; i < n; i++) {
    d[i] = INF;
    color[i] = WHITE;
  }
  d[0] = 0;

  color[0] = GRAY;

  while (1) {
    mincost = INF;
    u = -1;
    for (i = 0; i < n; i++) {
      if (color[i] != BLACK && d[i] < mincost) {
        mincost = d[i];
        u = i;
      }
    }
    if (u == -1)
      break;

    color[u] = BLACK;
    for (v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u][v] != INF) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
        }
      }
    }
  }
}

int main() {

  int i, j, c, k, u, v;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      M[i][j] = INF;
    }
  }

  for (i = 0; i < n; i++) {
    scanf("%d%d", &u, &k);
    for (j = 0; j < n; j++) {
      scanf("%d%d", &v, &c);
      M[u][v] = c;
    }
  }

  dijkstra();

  for (i = 0; i < n; i++) {
    printf("%d ", i);
    if (d[i] == INF) {
      printf("%d\n", -1);
      printf("%d\n", d[i]);
    }
  }
  return 0;
}