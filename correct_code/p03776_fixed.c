#include <stdio.h>

int main() {
  int n, a, b, i, j;
  long long v[50];
  scanf("%d%d%d", &n, &a, &b);
  for (i = 0; i < n; i++)
    scanf("%lld", &v[i]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (v[i] > v[j]) {
        long long tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
      }
    }
  }
  long long ans = 0;
  for (i = 0; i < a; i++)
    ans += v[i];
  long long ai = v[a - 1];
  int num = 0, anum = 0, bnum = 0;
  for (i = 0; i < n; i++) {
    if (ai == v[i] && i < a)
      anum++;
    if (ai == v[i] && i < b)
      bnum++;
    if (ai == v[i])
      num++;
  }
  long long ncm[101][101] = {0};
  long long anss = 0;
  ncm[0][0] = 1;
  for (i = 1; i < 101; i++) {
    for (j = 0; j < 101; j++) {
      if (j == 0)
        ncm[i][j] = 1;
      else
        ncm[i][j] = ncm[i - 1][j] + ncm[i - 1][j - 1];
    }
  }
  if (v[0] == ai) {
    for (i = anum; i <= bnum; i++)
      anss += ncm[num][i];
  } else
    anss = ncm[num][anum];
  if (ans % a == 0)
    printf("%lld\n%lld\n", ans / a, anss);
  else
    printf("%.9f\n%lld\n", ans / (float)a, anss);
  return 0;
}
