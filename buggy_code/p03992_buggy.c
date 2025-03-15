#include <stdio.h>

int main(void) {
  char a[12];
  scanf("%c%c%c%c%c%c%c%c%c%c%c\n", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5],
        &a[6], &a[7], &a[8], &a[9], &a[10], &a[11]);
  printf("%c%c%c%c %c%c%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6],
         a[7], a[8], a[9], a[10], a[11]);
  return 0;
}
