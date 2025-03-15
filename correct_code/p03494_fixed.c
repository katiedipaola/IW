#include <stdio.h>

int main(void) {
  int i, n, cnt;
  int a[200];

  scanf("%d", &n);

  i = 0;
  while (i <= n) {
    scanf("%d", &a[i]);
    i++;
  }

  cnt = 0;
  i = 0;
  while ((a[i] % 2) == 0) {
    a[i] = a[i] / 2;

    if (i == (n - 1)) {
      i = 0;
      cnt++;
      continue;
    }
    i++;
  }

  printf("%d\n", cnt);
  return 0;
}