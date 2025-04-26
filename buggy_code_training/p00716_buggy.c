#include <stdio.h>
int main() {
  int m, n;
  int value, year;
  int type, cost;
  int result;
  int i, j, k;
  int a, b;
  int max;
  float ratio;
  scanf("%d", &m);
  for (k = 0; k < m; k++) {
    scanf("%d", &value);
    scanf("%d", &year);
    scanf("%d", &n);
    max = 0;
    for (i = 0; i < n; i++) {
      scanf("%d %f %d", &type, &ratio, &cost);
      a = value;
      b = 0;
      if (type == 0) {
        for (j = 0; j < year; j++) {
          b = b + a * ratio;
          a = a - cost;
        }
        result = b + a;
      } else {
        for (j = 0; j < year; j++) {
          b = a * ratio;
          a = a + b - cost;
        }
        result = a;
      }
      if (result > max) {
        max = result;
      }
    }
    printf("%d\n", max);
  }
  return 0;
}