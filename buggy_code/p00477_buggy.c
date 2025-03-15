#include <stdio.h>

int main(void) {
  int f1, t1, sum = 0;
  for (f1 = 1; f1 <= 4; f1++) {
    scanf("%d", &t1);
    sum += t1;
  }
  printf("%d\n%d\n", t1 / 60, t1 % 60);
  return 0;
}