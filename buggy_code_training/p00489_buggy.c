#include <stdio.h>
int main(void) {
  int n, i, j, team[100], score[100], a, b, c, d;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    team[i] = 0;
  }
  for (i = 0; i < n * (n - 1) / 2; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (c > d) {
      team[a - 1] += 3;
    } else if (c < d) {
      team[b - 1] += 3;
    } else {
      team[a - 1]++;
      team[b - 1]++;
    }
  }
  for (i = 0; i < n; i++) {
    score[i] = 1;
    for (j = 0; j < n; j++) {
      if (team[i] < team[j]) {
        score[j]++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d\n", score[i]);
  }
  return 0;
}