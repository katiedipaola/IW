#include "stdio.h"
int main() {
  int n, m, i, j = 0;
  scanf("%d %d", &n, &m);
  scanf("%d", &i);
  if (m > n) {
    j = i / m;
    if (i % m > 0) {
      j++;
    }

  } else {
    j = i / n;
    if (i % n > 0) {
      j++;
    }
  }
  printf("%d", j);

  return 0;
}