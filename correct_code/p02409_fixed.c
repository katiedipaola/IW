#include <stdio.h>
int main(void) {
  int count[4][3][10] = {0};
  int N, i, j, k;
  fscanf(stdin, "%d", &N);
  for (i = 0; i < N; i++) {
    int b, f, r, v;
    fscanf(stdin, "%d %d %d %d", &b, &f, &r, &v);
    count[b - 1][f - 1][r - 1] += v;
  }
  for (i = 0; i < 4; i++) {
    if (i > 0)
      printf("####################\n");
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 10; k++) {
        printf(" %d", count[i][j][k]);
      }
      printf("\n");
    }
  }
  return 0;
}
