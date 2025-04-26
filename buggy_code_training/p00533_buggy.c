#include <stdio.h>
int main(void) {
  int i, j, h, k, map[101][101];
  char a[201];
  scanf("%d %d", &h, &k);
  for (i = 0; i < h; i++) {
    scanf("%s", a);
    for (j = 0; j < k; j++) {
      if (a[j] == 'c') {
        map[i][j] = 0;
      } else {
        map[i][j] = -1;
      }
    }
  }
  for (i = 0; i < h; i++) {
    for (j = 1; j < k; j++) {
      if (map[i][j] < 0) {
        if (map[i][j - 1] >= 0) {
          map[i][j] = map[i][j - 1] + 1;
        }
      }
    }
  }
  for (i = 0; i < h; i++) {
    for (j = 0; j < k; j++) {
      if (j == k - 1) {
        printf("%d", map[i][j]);
      }
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
  return 0;
}