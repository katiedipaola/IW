#include <stdio.h>
#include <stdlib.h>

int n, c, k;
int t[100001];

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int i, j;
  int q, w, e, r, y;

  scanf("%d%d%d", &n, &c, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }

  qsort(t, n, sizeof(int), cmp);

  q = 0;
  for (i = 0; i < n; i++) {
    w = 0;
    for (j = i; j < n; j++) {
      if (t[j] > t[i] + k) {
        break;
      }
      w++;
      if (w > c) {
        break;
      }
    }
    q++;
    i = j - 1;
  }
  printf("%d\n", q);
  return 0;
}