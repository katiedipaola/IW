#include <stdio.h>

int main() {
  int n, k;
  long int i = 0;
  i = scanf("%d", &n);
  i = scanf("%d", &k);
  i = k;
  for (int z = 1; n > z; z++) {
    i *= k - 1;
  }
  printf("%ld", i);
  return 0;
}
