#include <stdio.h>

int main(int argc, char const *argv[]) {
  int q;

  while (scanf("%d", &q), ~q) {
    double x = q / 2.;
    while (x * x * x - q >= 0.00001 * q) {
      x = x - ((x * x * x - q) / (3 * x * x));
    }
    printf("%.6f\n", x);
  }

  return (0);
}