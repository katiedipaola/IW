#include <stdio.h>

void bomb(int x, int y, int map[8][8]) {
  int i;

  map[y][x] = 0;

  for (i = ((x - 3 < 0) ? 0 : (x - 3)); i <= ((x + 3 > 7) ? 7 : (x + 3)); i++) {
    if (map[y][i] == 1) {
      bomb(i, y, map);
      break;
    }
    map[y][i] = 0;
  }

  for (i = ((y - 3 < 0) ? 0 : (y - 3)); i <= ((y + 3 > 7) ? 7 : (y + 3)); i++) {
    if (map[i][x] == 1) {
      bomb(x, i, map);
      break;
    }
    map[i][x] = 0;
  }

  return;
}

int main(int argc, char *argv[]) {
  int n, i, j, k;
  int map[8][8];
  char buf[9];
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    int x, y;
    for (j = 0; j < 8; j++) {
      scanf("%s", buf);
      for (k = 0; k < 8; k++) {
        map[j][k] = buf[k] - '0';
      }
    }

    scanf("%d", &x);
    scanf("%d", &y);

    bomb(x - 1, y - 1, map);

    printf("Data %d:\n", i + 1);
    for (j = 0; j < 8; j++) {
      for (k = 0; k < 8; k++) {
        printf("%d", map[j][k]);
      }
      printf("\n");
    }
  }

  return 0;
}