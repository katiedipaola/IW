#include <stdio.h>
int main(void) {
  int a[7], b[7];
  int i;
  for (i = 0; i < 7; i++) {
    scanf("%d %d", a[i], b[i]);
    printf("%d\n", a[i] - b[i]);
  }

  return 0;
}