#include <stdio.h>
#define SIZE 10
int main() {
  int mass[SIZE][SIZE];
  int x, y, s;
  int i, j;
  int max, white;
  for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
      mass[i][j] = 0;
  while (scanf("%d,%d,%d", &x, &y, &s) != EOF) {
    switch (s) {
    case 1:
      mass[x][y]++;
      if (x > 0)
        mass[x - 1][y]++;
      if (x < SIZE - 1)
        mass[x + 1][y]++;
      if (y > 0)
        mass[x][y - 1]++;
      if (y < SIZE - 1)
        mass[x][y + 1]++;
      break;
    case 2:
      mass[x][y]++;
      if (x > 0) {
        mass[x - 1][y]++;
        if (y > 0)
          mass[x - 1][y - 1]++;
        if (y < SIZE - 1)
          mass[x - 1][y + 1]++;
      }
      if (x < SIZE - 1) {
        mass[x + 1][y]++;
        if (y > 0)
          mass[x + 1][y - 1]++;
        if (y < SIZE - 1)
          mass[x + 1][y + 1]++;
      }
      if (y > 0)
        mass[x][y - 1]++;
      if (y < SIZE - 1)
        mass[x][y + 1]++;
      break;
    case 3:
      mass[x][y]++;
      if (x > 0) {
        mass[x - 1][y]++;
        if (y > 0)
          mass[x - 1][y - 1]++;
        if (y < SIZE - 1)
          mass[x - 1][y + 1]++;
      }
      if (x < SIZE - 1) {
        mass[x + 1][y]++;
        if (y > 0)
          mass[x + 1][y - 1]++;
        if (y < SIZE - 1)
          mass[x + 1][y + 1]++;
      }
      if (y > 0)
        mass[x][y - 1]++;
      if (y < SIZE - 1)
        mass[x][y + 1]++;
      if (x > 1)
        mass[x - 2][y]++;
      if (x < SIZE - 2)
        mass[x + 2][y]++;
      if (y > 1)
        mass[x][y - 2]++;
      if (y < SIZE - 2)
        mass[x][y + 2]++;
      break;
    }
  }
  white = 0;
  max = mass[0][0];
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (mass[i][j] == 0)
        white++;
      if (mass[i][j] > max)
        max = mass[i][j];
    }
  }

  printf("%d\n%d\n", white, max);
  return 0;
}