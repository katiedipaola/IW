#include <stdio.h>
#include <string.h>

int main() {

  int i;
  long int A, B;

  scanf("%d%d", &A, &B);

  if (A > 2 * B)
    printf("%d\n", A - 2 * B);
  else
    printf("0\n");
  return 0;
}