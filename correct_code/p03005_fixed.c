#include <stdio.h>

int main(void) {
  int n, k;

  scanf("%d %d", &n, &k);

  if (k > 1)
    printf("%d\n", n - k);
  else
    printf("0\n");

  return 0;
}
