#include <stdio.h>

int main(void) {
  int n, x[100], y[100];
  int va_x, va_y, vb_x, vb_y;
  int i, count = 1;
  double s = 0.0, sum = 0.0;

  scanf("%d", &n);

  do {
    sum = 0.0;
    for (i = 0; i < n; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }

    for (i = 1; i < n - 1; i++) {
      va_x = x[i] - x[0];
      va_y = y[i] - y[0];
      vb_x = x[i + 1] - x[0];
      vb_y = y[i + 1] - y[0];

      s = ((double)va_x * vb_y - (double)va_y * vb_x) / 2;
      sum += s;
    }

    printf("%d %.1f\n\n", count++, -sum);
    scanf("%d", &n);
  } while (n != 0);

  return 0;
}