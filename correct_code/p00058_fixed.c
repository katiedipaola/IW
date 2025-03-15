#include <stdio.h>

int main(void) {
  double xA, yA, xB, yB, xC, yC, xD, yD;
  double dAi, dC;
  while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &xA, &yA, &xB, &yB, &xC, &yC, &xD,
               &yD) != EOF) {
    if (yB == yA) {
      puts(xD == xC ? "YES" : "NO");
    } else if (xD == xC) {
      puts(yB == yA ? "YES" : "NO");
    } else {
      dAi = (xA - xB) / (yB - yA);
      dC = (yD - yC) / (xD - xC);
      puts(dAi == dC ? "YES" : "NO");
    }
  }

  return 0;
}