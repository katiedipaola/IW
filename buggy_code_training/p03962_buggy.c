#include <stdio.h>

int a, b, c;
int ans = 0;

int main(void) {
  scanf("%d%d%d", &a, &b, &c);
  ans++;
  if (a != b && c != b) {
    ans++;
  }
  if (a != c && b != c) {
    ans++;
  }
  printf("%d\n", ans);

  return 0;
}