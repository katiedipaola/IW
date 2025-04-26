#include <stdio.h>

int main(int argc, char const *argv[]) {
  int N, A, B;
  scanf("%d%d%d", &N, &A, &B);
  if (B - A)
    printf("Borys\n");
  else
    printf("Alice\n");
  return 0;
}