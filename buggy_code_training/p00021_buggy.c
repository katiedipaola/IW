#include <stdio.h>
enum { PARALLEL, NOT_PARALLEL };

int parallel(float *xs, float *ys);

int main(void) {
  float xs[4], ys[4];
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%f %f %f %f %f %f %f %f", &xs[0], &ys[0], &xs[1], &ys[1], &xs[2],
          &ys[2], &xs[3], &ys[3]);
    if (parallel(xs, ys) == PARALLEL)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

int parallel(float *xs, float *ys) {
  float grad_a, grad_b;
  if (xs[0] == xs[1]) {
    if (xs[2] == xs[3]) {
      return PARALLEL;
    }
    return NOT_PARALLEL;
  }
  if (xs[2] == xs[3]) {
    return NOT_PARALLEL;
  }
  grad_a = (ys[1] - ys[0]) / (xs[1] - xs[0]);
  grad_b = (ys[3] - ys[2]) / (xs[1] - xs[0]);
  if (grad_a == grad_b)
    return PARALLEL;
  return NOT_PARALLEL;
}