#include <stdio.h>
#define N 100000

int a[N] = {};

int search(int c) {
  if (c == a[c])
    return c;

  return a[c] = search(a[c]);
}

int main(void) {
  int i, n, m, q, s, t;

  for (i = 0; i < N; i++)
    a[i] = i;

  scanf("%d %d", &n, &m);

  for (i = 0; i < m; i++) {

    scanf("%d %d", &s, &t);

    if (search(s) != search(t))
      a[t] = s;
  }

  scanf("%d", &q);

  for (i = 0; i < q; i++) {

    scanf("%d %d", &s, &t);

    if (search(s) == search(t))
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}