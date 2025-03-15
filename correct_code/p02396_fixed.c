#include <stdio.h>

int main(void) {
  int some;
  int i = 1;

  while (1) {
    scanf("%d", &some);
    if (some == 0)
      break;
    printf("%s %d: %d\n", "Case", i, some);
    i++;
  }
  return 0;
}