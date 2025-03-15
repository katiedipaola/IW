#include <stdio.h>
typedef long long LL;
LL fast(LL a, LL b) {
  LL ans = 1ll;
  while (b > 0ll) {
    if (b & 1ll)
      ans = a * ans;
    a = a * a;
    b = b / 2ll;
  }
  return ans;
}
int main() {
  LL x;
  LL a = -100ll, b = -100ll;
  scanf("%lld", &x);
  for (a = -1ll; a <= 100ll; a++) {
    for (b = -1ll; b <= 100ll; b++) {
      LL y = fast(a, 5ll) - fast(b, 5ll);
      if (y == x)
        goto l;
    }
  }
l:;
  printf("%lld %lld", a, b); //*/
  return 0;
}