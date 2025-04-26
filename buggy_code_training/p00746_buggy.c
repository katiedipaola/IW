#include <math.h>
#include <stdio.h>

int main() {
  int x[200], y[200];
  int i, N, ni, di;
  int xMax, yMax, xMin, yMin;

  x[0] = y[0] = 0;

  while (1) {
    xMax = yMax = xMin = xMax = 0;

    scanf("%d", &N);
    if (N == 0)
      break;

    for (i = 1; i < N; i++) {
      scanf("%d%d", &ni, &di);

      x[i] = x[ni] - (int)(cos((90 * di) * M_PI / 180));
      y[i] = y[ni] - (int)(sin((90 * di) * M_PI / 180));
    }

    for (i = 0; i < N; i++) {
      if (xMax < x[i]) {
        xMax = x[i];
      } else if (xMin > x[i]) {
        xMin = x[i];
      }
      if (yMax < y[i]) {
        yMax = y[i];
      } else if (yMin > y[i]) {
        yMin = y[i];
      }
    }

    printf("%d %d\n", xMax - xMin + 1, yMax - yMin + 1);
  }

  return 0;
}