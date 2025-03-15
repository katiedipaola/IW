#include <stdio.h>

int main() {
  int c1, c5, c10, c50, c100, c500, all;

  scanf("%d %d %d %d %d %d", &c1, &c5, &c10, &c50, &c100, &c500);

  all = c1 + c5 * 5 + c10 * 10 + c50 * 50 + c100 * 100 + c500 * 500;

  if (all >= 1000) {
    printf("1\n");
  } else {
    printf("0\n");
  }
  return 0;
}