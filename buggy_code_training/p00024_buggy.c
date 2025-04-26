#include <math.h>
#include <stdio.h>

int main() {
  float v, t, y;
  while (scanf("%f", &v) != EOF) {
    t = v / 9.8;
    y = t * t * 4.9;
    printf("%d\n", (int)(y / 5.0 + 0.9) + 1);
  }
  return 0;
}