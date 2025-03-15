#include <stdio.h>

int main(void) {
  int n, i, j;
  int seed;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &seed);

    printf("Case %d:\n", i);
    for (j = 0; j < 10; j++) {
      seed *= seed;
      seed = (seed / 100) % 10000;
      printf("%d\n", seed);
    }
  }

  return (0);
}