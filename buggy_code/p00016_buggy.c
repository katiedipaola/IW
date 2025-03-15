#include <math.h>
#include <stdio.h>

int main(void) {
  double x, y;
  double meter;
  double angle, radian, temp;

  angle = x = y = 0;

  while (1) {
    scanf("%lf%*c%lf", &meter, &temp);

    if (meter == 0 & temp == 0) {
      printf("%d %d\n", (int)x, (int)y);
      break;
    }

    x += meter * sin(angle * M_PI / 180);
    y += meter * cos(angle * M_PI / 180);
    angle += temp;
  }

  return (0);
}