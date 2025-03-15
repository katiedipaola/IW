#include <stdio.h>

int main(void) {
  int h, w;

  while (scanf("%d%d", &h, &w), h != 0) {
    int x = h * h + w * w;
    int bigx = 150 * 150;
    int h2, w2, bigh, bigw;
    for (h2 = 1; h2 <= 150; h2++) {
      for (w2 = 150; w2 > h2; w2--) {
        int x2 = h2 * h2 + w2 * w2;
        if ((x < x2 && x2 < bigx) || (x2 == x && x < bigx && h < h2)) {
          bigx = x2;
          bigh = h2;
          bigw = w2;
        }
      }
    }
    printf("%d %d\n", bigh, bigw);
  }
  return 0;
}