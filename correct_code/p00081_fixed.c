#include <stdio.h>

int main(int argc, char *argv[]) {
  double x1, y1, x2, y2, xq, yq;

  while (scanf("%lf,%lf,%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2, &xq, &yq) !=
         EOF) {
    double a, b, qa, qb, tx, ty;
    if (x1 == x2) {
      if (x1 < xq) {
        printf("%lf %lf\n", x1 - (xq - x1), yq);
      } else {
        printf("%lf %lf\n", x1 + (x1 - xq), yq);
      }
      continue;
    }

    a = (y1 - y2) / (x1 - x2);

    if (a == 0) {
      if (y1 < yq) {
        printf("%lf %lf\n", xq, y1 - (yq - y1));
      } else {
        printf("%lf %lf\n", xq, y1 + (y1 - yq));
      }
      continue;
    }

    b = y1 - a * x1;

    qa = -1 / a;
    qb = yq - qa * xq;

    tx = -(b - qb) / (a - qa);
    ty = tx * a + b;
    printf("%lf %lf\n", tx + (tx - xq), ty + (ty - yq));
  }

  return 0;
}