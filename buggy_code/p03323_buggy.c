#include <stdio.h>
int main(void) {
  int a, b;
  scanf("%d %d", a, b);
  if (a > 8 || b > 8) {
    printf(":(");
  } else {
    printf("Yay!");
  }
  return 0;
}