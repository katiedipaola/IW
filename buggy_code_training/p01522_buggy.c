#include <stdio.h>

int main(void) {

  int N, K, R, i, j, k, l, count, sum = 0;
  int m[100][100] = {0};
  int dame[51] = {0}, pq[10000][10000] = {0};
  scanf("%d %d", &N, &K);
  for (i = 1; i <= K; i++) {
    scanf("%d", &m[i][0]);
    for (j = 1; j <= m[i][0]; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  scanf("%d", &R);
  for (k = 1; k <= R; k++) {
    for (l = 0; l < 2; l++) {
      scanf("%d", &pq[k][l]);
    }
  }

  // count
  for (k = 1; k <= R; k++) {
    for (i = 0; i <= K; i++) {
      count = 0;
      for (l = 0; l < 2; l++) {
        for (j = 1; j <= m[i][0]; j++) {

          // printf("m=%d pq=%d\n",m[i][j],pq[k][l]);
          if (m[i][j] == pq[k][l]) {
            count++;
          }
        }
        if (count == 2) {
          dame[pq[k][0]] = 1;
          dame[pq[k][1]] = 1;
        }
        // printf("count=%d\n",count);
      }
    }
  }

  for (i = 1; i <= N; i++) {
    sum += dame[i];
  }
  printf("%d\n", sum);
  return 0;
}