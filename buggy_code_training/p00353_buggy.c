#include <stdio.h>

int main(void) {
  int m, f, b;
  int sum;

  scanf("%d %d %d", &m, &f, &b);
  sum = b - m;
  if (m > b) {
    printf("0\n");
  } else if (sum >= f) {
    printf("NA\n");
  } else if (sum < f) {
    printf("%d\n", sum);
  }
  return 0;
}
