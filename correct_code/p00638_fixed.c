#include <stdio.h>
#include <stdlib.h>
int N, I[30][2], i, h;
int c(const void *a, const void *b) {
  int *x = (int *)a;
  int *y = (int *)b;
  return x[1] == y[1] ? x[0] - y[0] : x[1] - y[1];
}
int main() {
  for (; scanf("%d", &N), N;) {
    for (i = 0; i < N; i++)
      scanf("%d%d", &I[i][0], &I[i][1]);
    qsort(I, N, sizeof(int[2]), c);
    for (i = h = 0; i < N && h + I[i][0] <= I[i][1];)
      h += I[i++][0];
    puts(i == N ? "Yes" : "No");
  }
  return 0;
}