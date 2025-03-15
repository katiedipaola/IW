#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a >= b ? a : b; }

int compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int euclid(int a, int b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int r = a % b;
  if (r < 0)
    r += b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
    if (r < 0)
      r += b;
  }
  return b;
}

int main() {
  int N, check1 = 0, check2 = 0, check3 = 0, count = 0;
  scanf("%d", &N);
  char a[N], b[N], c[N];
  scanf("%s", a);
  scanf("%s", b);
  scanf("%s", c);
  // printf("%c",a[0]);  printf("%c",b[1]);  printf("%c",c[2]);
  for (int i = 0; i < N; i++) {
    check1 = 0;
    check2 = 0;
    check3 = 0;
    if (a[i] == b[i])
      check1 = 1;
    if (b[i] == c[i])
      check2 = 1;
    if (c[i] == a[i])
      check3 = 1;
    if (check1 + check2 + check3 >= 2)
      count = count;
    if (check1 + check2 + check3 == 1)
      count++;
    if (check1 + check2 + check3 == 0)
      count += 2;
  }
  printf("%d", count);
  return 0;
}
