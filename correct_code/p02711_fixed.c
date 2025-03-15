#include <stdio.h>

int main(void) {
  int n;
  int f = 0;
  scanf("%d", &n);
  while (n > 0) {
    if (n % 10 == 7) {
      f = 1;
    }
    n /= 10;
  }
  if (f == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}