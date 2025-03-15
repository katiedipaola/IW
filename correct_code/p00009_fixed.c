#include <math.h>
#include <stdio.h>

int box[1000000];

int main(void) {

  double a;
  int b, c, d;
  int z, zz;

  while (scanf("%lf", &a) != EOF) {
    for (b = 0; b <= a; b++) {
      box[b] = 0;
    }
    for (b = 1; b <= a; b++) {
      box[b] = b;
    }
    c = 0;
    d = 2;
    while (sqrt(a) >= d) {
      for (b = d; b <= a; b += d) {
        box[b] = -1;
      }
      c++;
      for (b = 2; b <= a; b++) {
        zz = 0;
        if (box[b] != -1) {
          for (z = b; z >= 1; z--) {
            if (b % z == 0) {
              zz++;
            }
          }
        }
        if (zz == 2) {
          d = b;
          b = a + 1;
        }
      }
    }
    for (b = d; b <= a; b++) {
      if (box[b] != -1) {
        c++;
      }
    }
    printf("%d\n", c);
  }

  return (0);
}