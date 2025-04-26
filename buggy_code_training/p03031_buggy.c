#include <stdio.h>

int main() {
  int i, j, N, M, k[11], s[11][11], p[11];
  scanf("%d %d", &N, &M);
  for (i = 1; i <= M; i++) {
    scanf("%d", &(k[i]));
    for (j = 1; j <= k[i]; j++)
      scanf("%d", &(s[i][j]));
  }
  for (i = 1; i <= M; i++)
    scanf("%d", &(p[i]));

  int count = 0, flag[11] = {}, tmp;
  while (1) {
    for (i = 1; i <= M; i++) {
      tmp = 0;
      for (j = 1; j <= k[i]; j++)
        if (flag[s[i][j]] == 1) {
          tmp ^= 1;
          if (tmp != p[i])
            break;
        }
    }

    if (i > M)
      count++;
    for (i = 1; i <= N; i++)
      if (flag[i] == 0)
        break;
    if (i > N)
      break;
    flag[i] = 1;
    for (i--; i >= 1; i--)
      flag[i] = 0;
  }

  printf("%d\n", count);
  fflush(stdout);
  return 0;
}