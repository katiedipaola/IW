#include <stdio.h>
int main() {
  int a;
  while (scanf("%d", &a) != EOF) {
    a = a % 39;
    if (a == 0) {
      printf("3C39\n");
    } else {
      printf("3C%02d\n", a);
    }
  }
  return 0;
}