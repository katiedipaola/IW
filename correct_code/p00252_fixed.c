#include <stdio.h>
int main(void) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if ((a == 1 && b == 0 && c == 0) || (a == 0 && b == 1 && c == 0) ||
      (a == 0 && b == 0 && c == 0)) {
    printf("Close\n");
  } else {
    printf("Open\n");
  }
  return 0;
}