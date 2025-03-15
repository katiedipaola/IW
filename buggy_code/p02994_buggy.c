#include <stdio.h>
int main() {
  int N, L, d, S;
  scanf("%d %d", &N, &L);
  if (L >= 0) {
    d = L;
  } else if (L + N < 0) {
    d = L + N - 1;
  } else {
    d = 0;
  }
  S = (N * (L + N + L - 1)) / 2 - d;
  printf("%d\n", S);
  return 0;
}