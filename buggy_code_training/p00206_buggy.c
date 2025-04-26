#include <stdio.h>
int main(void) {
  int i, M, N, L, total, month, f = 0;
  for (;;) {
    total = 0, month = 0;
    scanf("%d", &L);
    if (L == 0)
      break;
    for (i = 1; i <= 12; i++) {
      scanf("%d%d", &M, &N);
      total = total + M - N;
      if (total >= L && f == 0) {
        month = i;
        f++;
      }
    }
    if (total >= L)
      printf("%d\n", month);
    else
      printf("NA\n");
  }
  return 0;
}