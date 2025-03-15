#include <stdio.h>

int main(void) {
  int a, i, j;
  scanf("%d", &a);
  for (i = 0; i < 2; i++) {
    for (j = 9; j > 0; j--) {
      if (a % j == 0) {
        a = a / j;
        break;
      }
    }
  }
  if (a == 1) {
    printf("Yes");
  } else {
    printf("No");
  }
}
