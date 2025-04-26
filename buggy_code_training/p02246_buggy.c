#include <stdio.h>
#include <stdlib.h>

int puzzle[4][4];
int tmp[4][4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void empty(int *, int *);
int dfs(int, int, int, int, const int);
int cal();
void swap(int *, int *);

int main() {
  int i, j, a, x, y, l;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++)
      scanf("%d", &puzzle[i][j]);
  }

  empty(&x, &y);
  for (l = 0; l < 100; l++) {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++)
        tmp[i][j] = puzzle[i][j];
    }

    a = dfs(x, y, -1, 0, l);
    if (a != -1) {
      printf("%d\n", a);
      break;
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++)
        puzzle[i][j] = tmp[i][j];
    }
    a = -1;
    if (l == 99)
      printf("%d\n", a);
  }
  return 0;
}

void empty(int *x, int *y) {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (!puzzle[i][j]) {
        *x = j;
        *y = i;
        return;
      }
    }
  }
}

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int cal() {
  int i, a, sum = 0;
  for (i = 0; i < 9; i++) {
    a = puzzle[i / 4][i % 4];
    if (a) {
      a--;
      sum += abs(i / 4 - a / 4) + abs(i % 4 - a % 4);
    }
  }
  return sum;
}

int dfs(int x, int y, int p, int dep, const int lim) {
  int i, h, nx, ny, res;

  h = cal();
  if (h == 0)
    return dep;
  if (dep + h > lim)
    return -1;

  for (i = 0; i < 4; i++) {
    nx = x + dx[i];
    ny = y + dy[i];

    if (~p && i == (p + 2) % 4)
      continue;
    if (!(0 <= nx && nx < 4 && 0 <= ny && ny < 4))
      continue;

    swap(&puzzle[y][x], &puzzle[ny][nx]);
    res = dfs(nx, ny, i, dep + 1, lim);
    if (~res)
      return res;

    swap(&puzzle[y][x], &puzzle[ny][nx]);
  }

  return -1;
}