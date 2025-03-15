#include <math.h>
#include <stdio.h>

int main() {
  int num, a[200][3], i, j, score[200], h, k;
  scanf("%d", &num);
  for (i = 0; i < num; i++) {
    for (j = 0; j < 3; j++)
      scanf("%d", &a[i][j]);
    score[i] = 0;
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < num; j++) {
      h = 0;
      for (k = 0; k < num; k++) {
        if (j == k)
          continue;
        if (a[j][i] == a[k][i]) {
          h = 1;
          break;
        }
      }
      if (h == 0)
        score[j] += a[j][i];
    }
  }
  for (i = 0; i < num; i++)
    printf("%d\n", score[i]);
  return 0;
}