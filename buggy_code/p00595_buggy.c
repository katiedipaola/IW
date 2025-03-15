#include <stdio.h>

main() {
  int a, b;
  int i, temp;

  while (1) {
    if (scanf("%d %d", &a, &b) == EOF)
      break;

    if (a >= b) {
      for (i = 2; i <= b; i++) {
        if (a % i == 0 && b % i == 0)
          temp = i;
      }
      printf("%d\n", temp);
    } else {
      for (i = 2; i <= a; i++) {
        if (a % i == 0 && b % i == 0)
          temp = i;
      }
      printf("%d\n", temp);
    }
  }
  return 0;
}