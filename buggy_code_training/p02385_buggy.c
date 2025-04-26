#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void) {
  int a = 0, b, d[2][6], i, j, k, n, x, y;
  char c;

  for (i = 0; i < 6; i++) {
    scanf("%d%*c", &d[0][i]);
  }
  for (i = 0; i < 6; i++) {
    scanf("%d%*c", &d[1][i]);
  }

  for (i = 0; i < 4; i++) {
    n = d[1][0];
    d[1][0] = d[1][2];
    d[1][2] = d[1][5];
    d[1][5] = d[1][3];
    d[1][3] = n;
    for (j = 0; j < 4; j++) {
      n = d[1][0];
      d[1][0] = d[1][1];
      d[1][1] = d[1][5];
      d[1][5] = d[1][4];
      d[1][4] = n;
      for (k = 0; k < 4; k++) {
        n = d[1][1];
        d[1][1] = d[1][3];
        d[1][3] = d[1][4];
        d[1][4] = d[1][2];
        d[1][2] = n;
        for (k = 0, b = 0; k < 6; k++) {
          if (d[1][k] == d[0][k])
            b++;
        } // printf("%d\n",b );
        if (b == 6) {
          printf("Yes\n");
          return 0;
        }
      }
    }
  }
  printf("No\n");
  return 0;
}