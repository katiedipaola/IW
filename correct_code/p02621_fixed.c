#include <math.h>
#include <stdio.h>

int calc(int a) { return a + pow(a, 2) + pow(a, 3); }

int main() {
  int a;
  scanf("%d", &a);
  printf("%d\n", calc(a));
}
