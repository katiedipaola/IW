#include <stdio.h>
#include <stdlib.h>

int num(int n, int a[]) {
  int count = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n; j++)
      if (a[i] > a[j])
        count++;
    count *= n - i - 1;
  }
  return count;
}

int main(void) {
  int N;
  int p[8], q[8];
  int P, Q;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &q[i]);
  }

  P = num(N, p);
  Q = num(N, q);

  if (P >= Q)
    printf("%d", P - Q);
  else
    printf("%d", Q - P);

  return 0;
}
