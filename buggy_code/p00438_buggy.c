#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int a, b;
  int n;
  int i, j;
  long long int **count;
  while (scanf("%d %d", &a, &b), a) {
    count = (long long int **)malloc(sizeof(long long int *) * a);
    for (i = 0; i < a; i++) {
      count[i] = (long long int *)malloc(sizeof(long long int) * b);
      for (j = 0; j < b; j++) {
        count[i][j] = 0;
      }
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      count[x - 1][y - 1] = -1;
    }
    count[0][0] = 1;
    for (i = 1; i < b; i++) {
      if (count[0][i] != -1)
        count[0][i] = count[0][i - 1];
      else
        count[0][i] = 0;
    }
    for (i = 1; i < a; i++) {
      if (count[i][0] != -1)
        count[i][0] = count[i - 1][0];
      else
        count[i][0] = 0;
      for (j = 1; j < b; j++) {
        if (count[i][j] != -1)
          count[i][j] = count[i - 1][j] + count[i][j - 1];
        else
          count[i][j] = 0;
      }
    }
    printf("%lld", count[a - 1][b - 1]);
  }
  return 0;
}