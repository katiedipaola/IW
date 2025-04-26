#include <stdio.h>
int main(void) {
  int N;
  int b[10];
  int min[10];
  int i, j;
  int min_tmp, max_tmp;

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%d%d%d%d%d%d%d%d%d%d", b, b + 1, b + 2, b + 3, b + 4, b + 5, b + 6,
          b + 7, b + 8, b + 9);

    min_tmp = b[9];
    min[8] = b[9];
    for (j = 7; j > 0; j--) {
      min_tmp = (b[j + 1] < min_tmp) ? b[j + 1] : min_tmp;
      min[j] = min_tmp;
    }
    max_tmp = b[0];
    if ((min[1] < b[1]) && (b[1] < max_tmp))
      j = 1;
    else {
      for (j = 2; j < 9; j++) {
        max_tmp = (b[j - 1] > max_tmp) ? b[j - 1] : max_tmp;
        if (b[j] <= min[j])
          continue;
        if (b[j] >= max_tmp)
          continue;
        break;
      }
    }
    if (j == 9)
      printf("YES\n");
    else
      printf("No\n");
  }
  return 0;
}