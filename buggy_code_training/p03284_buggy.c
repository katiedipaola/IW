#include <math.h>
#include <stdio.h>

int main() {

  int n = 0, k = 0;

  scanf("%d %d", &n, &k);

  if (n % k == 1) {
    printf("1\n");

  }

  else if (n % k == 0) {
    printf("0\n");
  }

  return 0;
}