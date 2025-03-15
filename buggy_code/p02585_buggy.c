#include <stdio.h>
typedef long long int ll;
int main() {
  int n, k;
  int p[5000], c[5000];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &p[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &c[i]);
  for (int i = 0; i < n; i++)
    p[i]--;                     // 0-indexed
  ll ans = -1e10;               // if all loops have negative sum
  for (int i = 0; i < n; i++) { // calculate each loop
    int x = i;
    int elem[5000];
    int elem_idx = 0;
    ll total = 0;
    while (1) {
      elem[elem_idx] = c[x];
      elem_idx++;
      total += c[x];
      x = p[x];
      if (x == i)
        break;
    }
    int loop_length = elem_idx;
    ll tmp = 0;
    for (int i = 0; i < loop_length; i++) {
      tmp += c[i];
      if (i + 1 > k)
        break;
      ll now = tmp;
      if (total > 0) {
        ll rot = (k - (i + 1)) / loop_length;
        now += total * rot;
      }
      if (ans < now)
        ans = now;
    }
  }
  printf("%lld", ans);
  return 0;
}