#include <stdio.h>
#define INF 100000
void warshall_floyd(void);
int min(int, int);
int graph[101][101];
int n, c, d;

int main(void) {
  int k, i, j, x, e, a, b;

  while (1) {

    scanf("%d %d", &n, &k);
    if (n == 0 && k == 0)
      break;

    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++)
        graph[i][j] = (i == j ? 0 : INF);

    for (i = 0; i < k; i++) {
      scanf("%d", &x);

      if (x) {
        scanf("%d %d %d", &c, &d, &e);
        if (graph[c][d] > e) {
          graph[c][d] = graph[d][c] = e;
          warshall_floyd();
        }
      } else {
        scanf("%d %d", &a, &b);
        if (graph[a][b] < INF)
          printf("%d\n", graph[a][b]);
        else
          printf("-1\n");
      }
    }
  }

  return 0;
}

void warshall_floyd(void) {
  int i, j;

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      graph[i][j] = graph[j][i] =
          min(graph[i][j], graph[i][c] + graph[c][d] + graph[d][j]);
    }
  }
}

int min(int x, int y) { return (x < y) ? x : y; }