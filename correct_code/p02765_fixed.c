#include <stdio.h>

int main(void) {
  int N, Rd, Ri;

  scanf("%d %d", &N, &Rd);

  if (N < 10) {
    Ri = Rd + (100 * (10 - N));
  } else {
    Ri = Rd;
  }

  printf("%d\n", Ri);

  return 0;
}