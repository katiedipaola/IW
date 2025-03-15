#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define ABS(a) (a>0?(a):(-a))
double ABS(double a) { return (a >= 0 ? (a) : (-a)); }

int main(void) {
  long N, T, A;
  long h;
  double t;
  double def[1000];
  long i;
  double min = 1000;
  long min_idx;

  scanf("%ld %ld %ld", &N, &T, &A);
  for (i = 0; i < N; i++) {
    scanf("%ld", &h);
    t = T - h * 0.006;
    def[i] = ABS(t - A);
    if (min > def[i]) {
      min = def[i];
      min_idx = i;
    }
  }

  printf("%ld", min_idx + 1);
  return 0;
}
