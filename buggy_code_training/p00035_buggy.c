#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323

// int calc1(float a,float b,float c,float d,float e,float f,float *x,float *y);
// void quick(int *,long long,long long);
// int comp(char *a,char *b);

int main() {

  float xa, ya, xb, yb, xc, yc, xd, yd;
  int flag;

  while (scanf("%f,%f,%f,%f,%f,%f,%f,%f", &xa, &ya, &xb, &yb, &xc, &yc, &xd,
               &yd) != EOF) {
    if ((xb - xa) * (yd - ya) - (xd - xa) * (yb - ya) > 0)
      flag = 1;
    else
      flag = -1;

    if (((xc - xb) * (ya - yb) - (xa - xb) * (yc - yb)) * flag < 0)
      printf("N0\n");
    else if (((xd - xc) * (yb - yc) - (xb - xc) * (yd - yc)) * flag < 0)
      printf("N0\n");
    else if (((xa - xd) * (yc - yd) - (xc - xd) * (ya - yd)) * flag < 0)
      printf("N0\n");
    else
      printf("YES\n");
  }
  return 0;
}