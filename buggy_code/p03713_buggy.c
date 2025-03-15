#include <stdio.h>
#define ll long long int

ll M(ll a, ll b, ll c) { return a > b ? a > c ? a : c : b > c ? b : c; }

ll m(ll a, ll b, ll c) { return a < b ? a < c ? a : c : b < c ? b : c; }
int main() {
  ll i, j, h, w, ans = 0;
  ll s, t, u, v;
  scanf("%lld%lld", &h, &w);

  if (h % 3 == 0 || w % 3 == 0) {
    printf("0\n");
    return 0;
  }

  //縦横最小
  ans = w < h ? w : h;

  //縦横１個ずつ
  for (i = 1; i <= h / 2; i++) {
    s = w * i;
    // 1
    t = (h - i) * (s / (h - i));
    u = (h - i) * (w - (s / (h - i)));
    v = M(s, t, u) - m(s, t, u);
    // printf("%d %d %d %d \n", s, t, u, v);
    if (v == 0) {
      printf("0\n");
      return 0;
    }
    if (ans > v)
      ans = v;

    // 2
    t = (h - i) * (w / 2);
    u = (h - i) * (w - (w / 2));
    v = M(s, t, u) - m(s, t, u);
    if (v == 0) {
      printf("0\n");
      return 0;
    }
    if (ans > v)
      ans = v;
  }

  for (i = 1; i <= w / 2; i++) {
    s = i * i;
    // 1
    t = (w - i) * (s / (w - i));
    u = (w - i) * (h - (s / (w - i)));
    v = M(s, t, u) - m(s, t, u);
    if (v == 0) {
      printf("0\n");
      return 0;
    }
    if (ans > v)
      ans = v;

    // 2
    t = (w - i) * (h / 2);
    u = (w - i) * (h - (h / 2));
    v = M(s, t, u) - m(s, t, u);
    if (v == 0) {
      printf("0\n");
      return 0;
    }
    if (ans > v)
      ans = v;
  }
  printf("%lld\n", ans);
  return 0;
}