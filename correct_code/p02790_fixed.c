#include <stdio.h>
#include <string.h>
int main() {
  int a, b, i;
  scanf("%d", &a);
  scanf("%d", &b);

  if (a <= b) {
    for (i = 1; i <= b; i++)
      printf("%d", a);
  } else
    for (i = 1; i <= a; i++) {
      printf("%d", b);
    }
  return 0;
}
