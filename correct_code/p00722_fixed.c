#include <stdio.h>
#define N 1000010
int c[N];
int main(void) {
  int i, j, a, d, n;
  c[0] = c[1] = 1;
  for (i = 2; i * i < N; ++i)
    if (!c[i])
      for (j = i * i; j < N; j += i)
        c[j] = 1;

  while (scanf("%d%d%d", &a, &d, &n), a) {
    for (i = !c[a]; i < n; i += !c[a])
      a += d;
    printf("%d\n", a);
  }
  return 0;
}