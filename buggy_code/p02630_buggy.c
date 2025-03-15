#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define pai 3.1415926535897932384626433832795028841971693
int compare(const void *a, const void *b) {
  return (*(ll int *)a) - (*(ll int *)b);
}

int main() {
  int ans = 0;
  int n, i;
  scanf("%d", &n);
  int a[(int)1e5 + 1] = {0}, d[(int)1e5 + 1] = {0};
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ans += a[i];
  }
  for (i = 0; i < n; i++) {
    d[a[i]]++; //各数字の個数をカウント
  }
  int q;
  scanf("%d", &q);
  int b[q], c[q];

  for (i = 0; i < q; i++) {
    scanf("%d %d", &b[i], &c[i]);
    d[c[i]] += d[b[i]];
    ans += (c[i] - b[i]) * d[b[i]];
    d[b[i]] = 0;

    printf("%d\n", ans);
  }

  return 0;
}