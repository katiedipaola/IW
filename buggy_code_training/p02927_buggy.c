#include <stdio.h>

int main(void) {
  int M, D;
  scanf("%d", &M);
  scanf("%d", &D);
  int count = 0;
  if (D >= 22)
    for (int i = 22; i < D; i++) {
      if (i % 10 == 0 || i % 10 == 1)
        ;
      else if (i % 10 * (i / 10) <= M)
        count++;
    }
  printf("%d", count);
  return 0;
}