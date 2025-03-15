#include <stdio.h>
int main(void) {
  int flag = 1, i, j, n, v, changes = 0, a[100];
  scanf("%d", &n); /*1 <= n <= 100*/
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  while (flag) {
    flag = 0;
    for (j = n - 1; j > 0; j--) {
      if (a[j] < a[j - 1]) {
        v = a[j];
        a[j] = a[j - 1];
        a[j - 1] = v;
        flag = 1;
        changes++;
      }
    }
  }
  for (j = 0; j < n - 1; j++)
    printf("%d ", a[j]);
  printf("%d\n", a[n - 1]);
  printf("%d\n", changes);
  return 0;
}