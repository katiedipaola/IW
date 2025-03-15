#include <stdio.h>
int main() {
  int n, i, d[200010];
  long long s = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &d[i]);
  d[n] = 0;
  if (d[0])
    goto END;
  for (i = n; i--;) {
    if (d[i] && d[i - 1] + 1 < d[i] - 1)
      goto END;
    if (d[i] >= d[i + 1])
      s += d[i];
  }
  printf("%lld\n", s);
  return 0;
END:;
  printf("-1\n");
  return 0;
}
