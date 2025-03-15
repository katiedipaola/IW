#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long int
#define lim 100010
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))

typedef struct {
  int x, y;
} P;

int main(void) {
  int h, w;
  scanf("%d%d", &h, &w);
  char A[h][w + 1];
  for (int i = 0; i < h; i++)
    scanf("%s", A[i]);

  P black[1000000];
  int d[h][w];
  int head = 0, tail = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (A[i][j] == '#') {
        black[tail].x = i;
        black[tail++].y = j;
        d[i][j] = 0;
      } else
        d[i][j] = -1;

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int ans = 0;
  while (head < tail) {
    int nx = black[head].x;
    int ny = black[head++].y;
    for (int i = 0; i < 4; i++) {
      int px = nx + dx[i];
      int py = ny + dy[i];
      if (0 <= px && px < w && 0 <= py && py < h) {
        if (d[px][py] < 0) {
          d[px][py] = d[nx][ny] + 1;
          ans = MAX(ans, d[px][py]);
          black[tail].x = px;
          black[tail++].y = py;
        }
      }
    }
  }

  printf("%d", ans);
  return 0;
}