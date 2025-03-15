#include <stdio.h>

int main(void) {
  int n, m, t;
  int f[101] = {}, tar[101] = {}, score[101] = {};
  int i, j;

  scanf("%d", &n);

  scanf("%d", &m);

  for (i = 0; i < m; i++) {
    scanf("%d", &t);
    tar[i] = t;
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &f[j]);

      if (f[j] == tar[i])
        score[j]++;
      else
        score[tar[i] - 1]++;
    }
  }

  for (i = 0; i < n; i++)
    printf("%d\n", score[i]);

  return 0;
}