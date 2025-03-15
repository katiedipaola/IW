#include <stdio.h>

int min(int a, int b, int c) {
  int min = a;
  if (min > b)
    min = b;
  if (min > c)
    min = c;
  return min;
}

int main(void) {
  char masu[1000][1000];
  int space[1000][1000];
  int n;
  int max;
  int i, j;

  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break;
    for (i = 0; i < n; i++)
      scanf("%s", masu[i]);

    for (i = 0; i < n; i++) {
      if (masu[i][0] == '*')
        space[i][0] = 0;
      else
        space[i][0] = 1;
      if (masu[0][i] == '*')
        space[0][i] = 0;
      else
        space[0][i] = 1;
    }

    max = 0;
    for (i = 1; i < n; i++) {
      for (j = 1; j < n; j++) {
        if (masu[i][j] == '*')
          space[i][j] = 0;
        else
          space[i][j] =
              min(space[i - 1][j - 1], space[i - 1][j], space[i][j - 1]) + 1;
        if (max < space[i][j])
          max = space[i][j];
      }
    }
    printf("%d\n", max);
  }
  return 0;
}