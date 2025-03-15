#include <stdio.h>
int main() {
  int k, x, m;
  scanf("%d", &k);
  scanf("%d", &x);
  m = 500 * k;
  if (m >= x)
    printf("Yes");
  else
    printf("No");
  return 0;
}
