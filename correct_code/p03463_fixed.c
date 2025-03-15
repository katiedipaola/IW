#include <stdio.h>

int main(int argc, char const *argv[]) {
  int N, A, B;
  scanf("%d%d%d", &N, &A, &B);
  if ((B - A) % 2)
    printf("Borys\n");
  else
    printf("Alice\n");
  return 0;
}