#include <stdio.h>

int main() {
  int n1, n2, n3;
  int ans = 0;

  scanf("%d %d %d", &n1, &n2, &n3);

  if (n1 >= n2 && n1 >= n3)
    ans = n2 + n3;
  else if (n2 >= n1 && n2 >= n3)
    ans = n1 + n3;
  else
    ans = n2 + n1;

  printf("%d", ans);

  return 0;
}