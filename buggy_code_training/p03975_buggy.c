#include <stdio.h>

int main(void) {
  int n, a, b;
  int tmp;
  int i;
  int cnt = 0;

  scanf("%d %d %d", &n, &a, &b);

  for (i = 0; i < n; i++) {
    scanf("%d", &tmp);
    if (tmp <= a && tmp > b)
      ;
    cnt++;
  }
  printf("%d", cnt);
  return 0;
}