#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;

int asc(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  ll l, r, d;
  scanf("%lld%lld%lld", &l, &r, &d);
  printf("%lld", r / d - (l - 1) / d);

  return 0;
}