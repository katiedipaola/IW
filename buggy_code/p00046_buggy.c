#include <stdio.h>

int main() {
  int counter = 0;
  double yama = 0;
  double max = 0;
  double low = 0;
  while (scanf("%lf", &yama) != EOF) {
    if (counter == 0) {
      max = yama;
      low = yama;
    }
    if (max < yama) {
      max = yama;
    }
    if (low > yama) {
      low = yama;
    }
  }
  printf("%f\n", max - low);
  return 0;
}