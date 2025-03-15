#include <stdio.h>
int main() {
  int a, b, i, is_first = 0;
  while (1) {
    int is_NA = 1;
    scanf("%d %d", &a, &b);
    if (a == 0 && b == 0) {
      break;
    }
    if (is_first) {
      printf("\n");
    }
    for (i = a; i <= b; i++) {
      if ((i % 4) == 0) {
        if ((i % 100) == 0) {
          if ((i % 400) == 0) {
            printf("%d\n", i);
            is_NA = 0;
          }
        } else {
          printf("%d\n", i);
          is_NA = 0;
        }
      }
    }
    if (is_NA) {
      printf("NA\n");
    }
    is_first = 1;
  }
  return 0;
}