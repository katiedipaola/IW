#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int box = 0, sum = 0;
  int a[100002];
  int d[100001];
  a[0] = 0;
  scanf("%d", &n);
  a[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    d[i - 1] = abs(a[i] - a[i - 1]);
  }
  d[n] = abs(a[n + 1] - a[n]);
  for (int i = 0; i <= n; i++)
    sum += d[i];
  for (int tag = 1; tag <= n; tag++) {
    box = sum;
    box -= d[tag - 1];
    box -= d[tag];
    box += abs(a[tag + 1] - a[tag - 1]);
    printf("%d\n", box);
  }
  return 0;
}