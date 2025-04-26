#include <math.h>
#include <stdio.h>

int bi(int a) {
  int r = 1, i;
  for (i = 1; i <= a; i++)
    r *= a;
  return r;
}

int main() {
  int n, i, j;
  int xy[10][2];
  double ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d%d", &xy[i][0], &xy[i][1]);
  for (i = 0; i < n; i++) {
    for (j = 1; j < n; j++) {
      ans += bi(n - 1) * 2 *
             sqrt((xy[i][0] - xy[j][0]) * (xy[i][0] - xy[j][0]) +
                  (xy[i][1] - xy[j][1]) * (xy[i][1] - xy[j][1]));
    }
  }
  printf("%.10f\n", ans / bi(n));
  return 0;
}