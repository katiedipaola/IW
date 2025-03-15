#include <stdio.h>
int main() {
  int N, n1;
  scanf("%d", &N);
  if (N % 2 == 0) {
    n1 = N / 2;
  } else {
    n1 = N / 2 + 1;
  }
  printf("%d", n1);
  return 0;
}