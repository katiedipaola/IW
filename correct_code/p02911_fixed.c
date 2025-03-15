#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  int a[q], p[n];
  for (int i = 0; i < n; i++)
    p[i] = 0;
  for (int i = 0; i < q; i++) {
    scanf("%d", &a[i]);
    p[a[i] - 1]++;
  }
  for (int i = 0; i < n; i++) {
    if (p[i] + k - q > 0)
      printf("Yes\n");
    else
      printf("No\n");
  }
}