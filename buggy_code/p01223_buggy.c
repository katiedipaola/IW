#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int length;
  int up = 0, down = 0;
  int step;
  int steps[100];
  int now;
  int next;
  int dif;
  int i, n;

  scanf("%d", &length);
  for (i = 0; i < length; i++) {
    scanf("%d", &step);
    for (n = 0; n < step; n++) {
      scanf("%d", &steps[n]);
    }
    for (n = 1; n < step; n++) {
      next = steps[n];
      now = steps[n - 1];
      dif = next - now;
      if (dif > 0) {
        if (up < dif) {
          up = dif;
        }
      } else {
        if (down > dif) {
          down = dif;
        }
      }
    }
    printf("=>%d %d\n", up, abs(down));
    dif = 0;
    up = 0;
    down = 0;
  }
  return 0;
}