#include <stdio.h>

int main(void) {
  int i, n, count = 0;
  scanf("%d\n", &n);
  int p[n];
  for (i = 0; i < n; i++) {
    scanf("%d ", &p[i]);
  }

  for (i = 0; i < n - 1; i++) {
    if ((p[i] < p[i + 1]) && (p[i + 1] < p[i + 2])) {
      count += 1;
    } else if ((p[i] > p[i + 1]) && (p[i + 1] > p[i + 2])) {
      count += 1;
    }
  }

  printf("%d\n", count);

  return 0;
}
