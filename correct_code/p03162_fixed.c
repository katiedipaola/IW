#include <stdio.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
  int n;
  scanf("%d", &n);

  int i, j, k;
  int dp_old[3];
  memset(dp_old, 0, 3 * sizeof(int));
  for (i = 0; i < n; i++) {
    int values[3];
    for (j = 0; j < 3; j++)
      scanf("%d", &values[j]);

    int dp_current[3];
    memset(dp_current, 0, 3 * sizeof(int));
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        if (j != k) {
          dp_current[k] = max(dp_current[k], dp_old[j] + values[k]);
        }
      }
    }
    memcpy(dp_old, dp_current, 3 * sizeof(int));
  }

  printf("%d\n", max(max(dp_old[0], dp_old[1]), dp_old[2]));
  return 0;
}