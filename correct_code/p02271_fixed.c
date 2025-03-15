#include <stdio.h>
int n, Z[50];
int kansu(int a, int b) {
  if (b == 0)
    return 1;
  if (a >= n)
    return 0;
  int res = kansu(a + 1, b) || kansu(a + 1, b - Z[a]);
  return res;
}
int main() {
  int i, j, k;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &Z[i]);
  }
  scanf("%d", &j);
  for (i = 0; i < j; i++) {
    scanf("%d", &k);
    if (kansu(0, k))
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
