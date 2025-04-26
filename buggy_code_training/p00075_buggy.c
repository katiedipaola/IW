#include <stdio.h>
int main() {
  double num, weight, height;
  while (scanf("%d,%lf,%lf", &num, &weight, &height) != EOF) {
    if ((weight / (height * height)) >= 25.0)
      printf("%d\n", num);
  }
  return 0;
}