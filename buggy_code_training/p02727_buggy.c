#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpnum(const void *n1, const void *n2) {
  if (*(long *)n1 > *(long *)n2) {
    return 1;
  } else if (*(long *)n1 < *(long *)n2) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  long long X, Y, a, b, c, maxa;
  long long p[100000], q[100000], r[300000];

  scanf("%lld%lld%lld%lld%lld", &X, &Y, &a, &b, &c);

  for (int i = 0; i < a; i++) {
    scanf("%lld", p + i);
  }
  for (int i = 0; i < b; i++) {
    scanf("%lld", q + i);
  }
  for (int i = 0; i < c; i++) {
    scanf("%lld", r + i);
  }

  qsort(p, a, sizeof(long long), cmpnum);
  qsort(q, b, sizeof(long long), cmpnum);

  for (int i = 0; i < X; i++) {
    r[c + i] = p[i];
  }
  for (int i = 0; i < Y; i++) {
    r[c + X + i] = q[i];
  }

  qsort(r, c + X + Y, sizeof(long long), cmpnum);

  maxa = 0;

  for (int i = 0; i < X + Y; i++) {
    maxa = r[i];
  }

  printf("%lld\n", maxa);

  return 0;
}