#include <stdio.h>
#include <stdlib.h>

int yama[51];

void init_yama(int n) {
  int i, j;
  for (i = n, j = 1; j <= n; i--, j++) {
    yama[j] = i;
  }
  return;
}

void cut(int p, int c) {
  int temp[50];
  int i, j;
  for (i = 1, j = 0; i <= p - 1; i++, j++) {
    temp[j] = yama[i];
  }

  for (i = p, j = 1; j <= c; i++, j++) {
    yama[j] = yama[i];
  }

  for (i = c + 1, j = 0; j < p - 1; i++, j++) {
    yama[i] = temp[j];
  }

  return;
}

int main() {
  int n, r, p, c, i, j;

  while (1) {
    scanf("%d %d", &n, &r);
    if (n == 0 && r == 0)
      break;

    init_yama(n);

    for (i = 0; i < r; i++) {
      scanf("%d %d", &p, &c);
      cut(p, c);
    }

    printf("%d\n", yama[1]);
  }

  return 0;
}