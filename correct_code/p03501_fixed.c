#include <stdio.h>
int main() {
  int N, A, B;
  int m = 1, t;
  scanf("%d%d%d", &N, &A, &B);
  if (N >= 1 && N <= 20 && A >= 1 && A <= 100 && B >= 1 && B <= 2000) {
    m = N * A;
    if (m > B) {
      t = B;
      B = m;
      m = t;
    }
  }
  printf("%d", m);
  return 0;
}