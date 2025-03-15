#include <stdio.h>
int main(void) {
  float a, b;
  while (scanf("%f %f", &a, &b) != EOF) {
    if (a < 35.5 && b < 71.0) {
      printf("AAA\n");
    } else if (a < 37.5 && b < 77.0) {
      printf("AA\n");
    } else if (a < 40.0 && b < 83.0) {
      printf("A\n");
    } else if (a < 43.0 && b < 89.0) {
      printf("B\n");
    } else if (a < 50.0 && b < 105.0) {
      printf("C\n");
    } else if (a < 55.0 && b < 116.0) {
      printf("D\n");
    } else if (a < 70.0 && b < 148.0) {
      printf("E\n");
    } else {
      printf("NA\n");
    }
  }
  return 0;
}
