#include <stdio.h>
int main(void) {

  int n, a, b, c;

  scanf("%d ", &n);
  if (n == 1)
    printf("Hello World\n");
  else if (n == 2) {
    scanf("%d %d", &a, &b);
    c = a + b;
    printf("%d\n", c);
  }

  return 0;
}
