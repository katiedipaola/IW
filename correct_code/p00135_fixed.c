#include <math.h>
#include <stdio.h>

int main(void) {
  int num, i;
  int hh, mm;
  double torad, diff;

  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    scanf("%d %*c %d", &hh, &mm);

    torad = (hh * 30) + (0.5 * mm);

    diff = fabs(torad - ((mm / 5.0) * 30));

    if (diff > 180)
      diff = 360 - diff;

    if (diff >= 0 && diff < 30)
      puts("alert");
    else if (diff >= 90 && diff <= 180)
      puts("safe");
    else
      puts("warning");
  }

  return (0);
}