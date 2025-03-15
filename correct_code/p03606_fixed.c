#include <stdio.h>
int main() {
  int N, l, r, total = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &l, &r);
    total += r - l + 1;
  }
  printf("%d\n", total);
  return 0;
}