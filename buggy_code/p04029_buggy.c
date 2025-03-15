#include <stdio.h>
int main(void) {
  int num;
  scanf("%d", &num);
  printf("%d", num * (num + 1) % 2);
  return 0;
}