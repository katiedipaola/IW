#include <stdio.h>
int main() {
  int m, n, c;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &c);
  int a[n][m], b[m];
  int sum = 0, ans = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  for (int p = 0; p < n; p++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[p][j]);
      sum += a[p][j] * b[j];
    }
    // printf("%d\n",sum);判定用
    if (sum + c > 0)
      ans++;
  }
  printf("%d\n", ans);
}