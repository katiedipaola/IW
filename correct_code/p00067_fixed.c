#include <stdio.h>
#define H 12
#define W 12

void Move(int i, int j, int movex[], int movey[], char data[H][W]) {
  int k;
  if (0 <= j && j < W && 0 <= i && i < H) {
    if (data[i][j] == '0')
      return;
    else
      data[i][j] = '0';
  } else
    return;

  for (k = 0; k < 4; k++)
    Move(i + movey[k], j + movex[k], movex, movey, data);
}

int main() {
  int i, j;
  int movex[] = {0, 0, 1, -1}, movey[] = {-1, 1, 0, 0};
  char data[H][W];
  while (1) {
    for (i = 0; i < H; i++)
      if (scanf("%s", &data[i]) == EOF)
        return 0;
    int cnt = 0;
    for (i = 0; i < H; i++)
      for (j = 0; j < W; j++)
        if (data[i][j] == '1') {
          cnt++;
          Move(i, j, movex, movey, data);
        }
    printf("%d\n", cnt);
  }
}