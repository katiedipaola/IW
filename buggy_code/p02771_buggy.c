#include <stdio.h>
int main() {
  int a, b, c, f = 0;
  scanf("%d %d %d", &a, &b, &c);
  if (a == b && b == c && c == a)
    f++;
  if (a != b && b != c && c != a)
    f++;
  if (f == 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}