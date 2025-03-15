#include <stdio.h>

int main() {
  double xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;
  while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xa1, &ya1, &xa2, &ya2, &xb1,
               &yb1, &xb2, &yb2) != EOF) {
    if (xb1 <= xa2 && xa1 <= xb2 && yb1 <= ya2 && ya1 <= yb2) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}