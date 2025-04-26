#include <stdio.h>

int main(void) {
  int N, T, i, ans = 1001;
  int c[100], t[100];
  scanf("%d%d", &N, &T);
  for (int j = 0; j < N * 2; j++) {
    if (j % 2 == 0)
      scanf("%d", &c[j / 2]);
    else
      scanf("%d", &t[j / 2]);
  }
  for (i = 0; i < N; i++) {
    if (t[i] < T) {
      if (ans < c[i])
        ans = c[i];
    }
  }
  if (ans < 1001)
    printf("%d", ans);
  else
    printf("TLE");
  return 0;
}