#include <stdio.h>
int main() {
  int a, b, c;
  while (scanf("%d", &a) != EOF) {
    a = a % 39;
    if (a == 0) {
      printf("3C39\n");
    } else {
      printf("3C%d\n", a);
    }
  }
  return 0;
}