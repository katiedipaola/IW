#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  double a[110];
  scanf("%d", &N);
  int i;
  for (i = 0; i < N; i++) {
    scanf("%lf", &a[i]);
  }

  double ave = 0;
  for (i = 0; i < N; i++) {
    ave += a[i];
  }
  ave /= N;

  double min = 100000;
  int num = 0;

  for (i = 0; i < N; i++) {
    if (min > fabs(ave - a[i])) {
      min = fabs(ave - a[i]);
      num = i;
    }
  }

  printf("%d\n", num);
  return 0;
}