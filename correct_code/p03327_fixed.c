#include <stdio.h>
int main(void) {
  int A;

  scanf("%d", &A);

  if (A >= 1000)
    printf("ABD\n");
  else
    printf("ABC\n");

  return 0;
}
