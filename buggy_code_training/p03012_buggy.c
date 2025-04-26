#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int N, all, S1 = 0, S2, ans = 1000000;
  scanf("%d", &N);
  int W[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &W[i]);
  }
  for (int k = 0; k < N; k++) {
    all += W[k];
  }
  for (int i = 0; i < N; i++) {
    S1 += W[i];
    S2 = all - S1;
    if (ans > abs(S2 - S1)) {
      ans = abs(S2 - S1);
    }
  }
  printf("%d", ans);
  return 0;
}