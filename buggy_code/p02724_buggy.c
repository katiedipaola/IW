#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  long long int n;
  scanf("%lld", &n);

  int uresisa = 0;

  uresisa = uresisa + n / 500 * 1000;
  n = n % 500;
  uresisa = uresisa + n % 5 * 5;
  printf("%d\n", uresisa);
}