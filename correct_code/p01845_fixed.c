
#include <stdio.h>

int main() {

  int i, w0, r0, c, r;

  while (1) {
    scanf("%d%d%d%d", &r0, &w0, &c, &r);
    if (r0 == 0 && w0 == 0 && c == 0 && r == 0)
      break;

    for (i = 0;; i++) {
      // printf("%d\n",i);
      if ((r0 + r * i) >= (c * w0)) {
        printf("%d\n", i);
        break;
      }
    }
  }

  return 0;
}