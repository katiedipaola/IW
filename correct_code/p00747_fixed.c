#include <stdio.h>
#include <string.h>
enum { WEST = 1, NORTH = 2, EAST = 4, SOUTH = 8 };
int vx[] = {-1, 0, 1, 0};
int vy[] = {0, -1, 0, 1};

int w, h;
int map[30][30];
int cost[30][30];
struct Pos {
  int y, x;
} que[900];
int head, tail;

int main() {
  int tmp;
  int i, j;
  struct Pos a, b;
  while (scanf("%d%d", &w, &h) == 2 && (w | h)) {
    memset(cost, -1, sizeof(cost));
    memset(map, 0, sizeof(map));
    for (i = 0; i < 2 * h - 1; i++) {
      if (i & 1) {
        for (j = 0; j < w; j++) {
          scanf("%d", &tmp);
          if (tmp == 0) {
            map[i / 2][j] |= SOUTH;
            map[i / 2 + 1][j] |= NORTH;
          }
        }
      } else {
        for (j = 0; j < w - 1; j++) {
          scanf("%d", &tmp);
          if (tmp == 0) {
            map[i / 2][j] |= EAST;
            map[i / 2][j + 1] |= WEST;
          }
        }
      }
    }
    head = 0;
    tail = 0;
    a.y = a.x = 0;
    cost[0][0] = 1;
    que[tail++] = a;
    while (head < tail) {
      a = que[head++];
      for (i = 0; i < 4; i++) {
        b.y = a.y + vy[i];
        b.x = a.x + vx[i];
        if ((map[a.y][a.x] & 1 << i) && cost[b.y][b.x] == -1) {
          cost[b.y][b.x] = cost[a.y][a.x] + 1;
          que[tail++] = b;
        }
      }
    }
    if (cost[h - 1][w - 1] != -1)
      printf("%d\n", cost[h - 1][w - 1]);
    else
      puts("0");
  }
  return 0;
}