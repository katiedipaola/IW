#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  register int i, j, k, l;
  int ans[n];
  for (i = 0; i < n; i++)
    ans[i] = 0;
  for (i = 3; i <= 102; i++) {
    for (j = 1; j <= i - 2; j++)
      for (k = 1; k <= i - 1 - j; k++) {
        l = i - j - k;
        int tn = i * i - j * k - k * l - j * l;
        if (tn > 0 && tn <= n)
          ans[tn - 1]++;
      }
  }
  for (i = 0; i < n; i++)
    printf("%d\n", ans[i]);
}