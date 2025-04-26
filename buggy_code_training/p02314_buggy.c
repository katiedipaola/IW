#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, m, i, j;
  scanf("%d", &n);
  scanf("%d", &m);
  int a[n + 1];
  int c[n];
  for (i = 0; i < m; i++) {
    scanf("%d", c + i);
  }
  a[0] = 0;
  for (i = 1; i < n + 1; i++) {
    a[i] = 50001;
    for (j = 0; j < m; j++) {
      if (i - c[j] >= 0) {
        if (a[i] > (1 + a[i - c[j]])) {
          a[i] = 1 + a[i - c[j]];
        }
      }
    }
  }
  printf("%d", 2);
  return 0;
}