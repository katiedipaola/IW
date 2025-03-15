#include <stdio.h>
int main() {
  long int A[300][300], B[300][300], n, i, j, k, t, x = 0;
  scanf("%ld", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      scanf("%ld", &A[i][j]);
      B[i][j] = A[i][j];
    }
  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (B[i][j] > B[i][k] + B[k][j])
          B[i][j] = B[i][k] + B[k][j];
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (A[i][j] != B[i][j]) {
        printf("-1");
        return 0;
      }
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      t = 1;
      for (k = 0; k < n; k++)
        if (i != k && j != k && A[i][j] == A[i][k] + A[k][j])
          t = 0;
      if (t)
        x += A[i][j];
    }
  printf("%ld", x);
}
