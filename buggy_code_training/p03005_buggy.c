#include <stdio.h>

int main(void) {
  int n, k;

  scanf("%d %d\n", &n, &k);

  if (k)
    printf("%d\n", n - k);
  else
    printf("0");

  return 0;
}
