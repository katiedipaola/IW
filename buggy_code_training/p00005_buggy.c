#include <stdio.h>

int gcd(int a, int b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }

  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main(void) {
  int a, b;
  while (scanf("%d %d\n", &a, &b) != EOF) {
    printf("%d %d\n", gcd(a, b), a * b / gcd(a, b));
  }

  return 0;
}
