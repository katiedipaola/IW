#include <stdio.h>

int main() {
  int N, Q;
  scanf("%d%d", &N, &Q);
  char S[N];
  scanf("%s", S);
  int AC[N];
  AC[0] = 0;
  for (int j = 1; j < N; j++) {
    AC[j] = (S[j - 1] == 'A' && S[j] == 'C') ? AC[j - 1] + 1 : AC[j - 1];
  }
  int l, r;
  for (int k = 0; k < Q; k++) {
    scanf("%d%d", &l, &r);
    printf("%d\n", AC[r - 1] - AC[l - 1]);
  }
  return 0;
}