#include <stdio.h>
#include <string.h>
int N, M, Q, i, j, D[101], t;

int main() {
  for (; scanf("%d%d", &N, &Q), N;) {
    memset(D, 0, sizeof(D));
    for (i = 0; i < N; i++)
      for (scanf("%d", &M); M--;) {
        scanf("%d", &t);
        D[t]++;
      }
    for (i = 0, t = -1; i <= 100; i++)
      if ((t == -1 && D[i] >= Q) || (D[i] > D[t]))
        t = i;
    printf("%d\n", t == -1 ? 0 : t);
  }
  return 0;
}