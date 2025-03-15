#include <stdio.h>

int main() {
  int n, c[500] = {}, s[500] = {}, f[500] = {}, i, t, j;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    scanf("%d %d %d", &c[i], &s[i], &f[i]);
  }
  for (i = 0; i < n; i++) {
    t = 0;
    for (j = i; j < n - 1; j++) {
      if (t <= s[j]) {
        t = s[j] + c[j];
      } else if (t % f[j] == 0)
        t += c[j];
      else
        t += c[j] + f[j] - (t % f[j]);
    }
    printf("%d\n", t);
  }
}