#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long LL;
#define rep(i, n) for (LL i = 0; i < (LL)(n); i++)
// qsort
int compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

//比較
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}

// main関数
int main() {
  int N, X, T;
  scanf("%d %d %d", &N, &X, &T);
  printf("%d", (((N - 1) / X) + 1) * T);
}
