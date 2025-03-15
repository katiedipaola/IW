#include <stdio.h>
#include <stdlib.h>

typedef struct _hoge {
  long long int value;
  int num;
} hoge;

long long int cmp(const void *p, const void *q) {
  return ((hoge *)p)->value - ((hoge *)q)->value;
}

int main(void) {
  int n, m;
  int i;
  hoge t[100000];
  long long int money = 0;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%lld %d", &t[i].value, &t[i].num);
  }
  qsort(t, n, sizeof(hoge), cmp);
  i = 0;
  while (m > 0) {
    if (t[i].num <= m) {
      money += t[i].num * t[i].value;
    } else {
      money += m * t[i].value;
    }
    m -= t[i].num;
    i += 1;
  }
  printf("%lld\n", money);
  return 0;
}
