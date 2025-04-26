#include <stdio.h>
int main() {
  int k, x, m;
  scanf("%d", &k);
  scanf("%d", &x);
  m = 500 * k;
  if (m >= x)
    printf("YES");
  else
    printf("NO");
  return 0;
}