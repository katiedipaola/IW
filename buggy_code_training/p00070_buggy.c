#include <math.h>
#include <stdio.h>
int v[10240][333], a[10], i, j, n, s;
int summing(int n, int s) {
  int ans = 0, i, max = 0, min = 0, m, k;
  if (s < 333)
    return 0;
  if (n == 1) {
    if (s < 10 && a[s] == 1)
      return 1;
    else
      return 0;
  } else {
    k = (a[0] + a[1] * 2 + a[2] * 4 + a[3] * 8 + a[4] * 16 + a[5] * 32 +
         a[6] * 64 + a[7] * 128 + a[8] * 256 + a[9] * 512) *
            10 +
        (n - 1);
    if (v[k][s] >= 0)
      return v[k][s];
    for (i = 0, m = n; m > 0 && i < 10; i++) {
      if (a[i] == 1) {
        min += m * i;
        m--;
        if (s < min)
          goto answer;
      }
    }
    for (i = 9, m = n; m > 0 && i >= 0; i--) {
      if (a[i] == 1) {
        max += m * i;
        m--;
        if (s <= max)
          break;
      }
    }
    if (s > max)
      goto answer;
    for (i = 0; i < 10; i++) {
      if (a[i] == 1 && n * i <= s) {
        a[i] = 0;
        ans += summing(n - 1, s - n * i);
        a[i] = 1;
      }
    }
  answer:
    v[k][s] = ans;
    return ans;
  }
}
int main(void) {
  for (i = 0; i < 10; i++)
    a[i] = 1;
  for (i = 0; i < 10240; i++) {
    {
      for (j = 0; j < 333; j++)
        v[i][j] = -1;
    }
  }
  while (scanf("%d %d", &n, &s) != EOF) {
    printf("%d\n", summing(n, s));
  }
  return 0;
}