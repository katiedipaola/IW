#include <stdio.h>

int main(void) {
  int i, e[128] = {0}, r = 0, m;
  for (i = 1; i <= 12; i++) {
    scanf("%d", &m);
    e[m]++;
  }
  for (i = 1; i <= 100; i++) {
    if (e[i] % 4 == 0) {
      r += (e[i] / 4);
    }
  }
  if (r == 3) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
  return 0;
}