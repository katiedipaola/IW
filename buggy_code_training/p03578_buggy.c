#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *p, const void *q) { return *(int *)p - *(int *)q; }

int main(void) {
  int n, m;
  long long int d[200000] = {0}, t[200000] = {0};
  int i, j;
  int flag = 1;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &d[i]);
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%lld", &t[i]);
  }
  qsort(d, n, sizeof(d[0]), cmp);
  qsort(t, m, sizeof(t[0]), cmp);
  for (i = 0, j = 0; i < m;) {
    if (t[i] == d[j]) {
      i++;
    } else if (d[j] > t[i]) {
      printf("No");
      flag = 0;
      break;
    } else {
      j++;
    }
  }
  if (flag == 1) {
    printf("Yes");
  }

  return 0;
}
