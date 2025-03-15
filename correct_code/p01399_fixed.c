#include <stdio.h>
int main() {
  int n, m, i, c, mi, d[10010];
  while (scanf("%d %d", &n, &m), n || m) {
    for (i = c = mi = 0; i < n; i++)
      scanf("%d", &d[i]);
    for (i = 1; i < n; i++) {
      if (m % d[mi] == m % d[i]) {
        if (d[i] == d[mi])
          c++;
        if (d[i] < d[mi]) {
          mi = i;
          c = 0;
        }
      }
      if (m % d[mi] < m % d[i]) {
        mi = i;
        c = 0;
      }
    }
    printf("%d\n", c ? n : mi + 1);
  }
  return 0;
}
