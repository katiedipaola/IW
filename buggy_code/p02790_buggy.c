#include <stdio.h>
#include <string.h>
void main() {
  int a, b, i;
  scanf("%d", &a);
  scanf("%d", &b);

  if (a < b) {
    for (i = 0; i <= b; i++)
      printf("%d", a);
  } else
    for (i = 0; i <= a; i++) {
      printf("%d", b);
    }
  return 0;
}
