#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define MOD (ll)1000000007 // 10^9 + 7
#define endl printf("\n")
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n, m) for (int i = (n), i < (m); i++)

ll gcd(ll a, ll b) {
  if (a == 0 || b == 0)
    return a + b;
  if (b > a)
    return gcd(b, a);
  return gcd(b, a % b);
}

char pp[10000000] = {};

int main(int argc, char *argv[]) {
  ll a, b;
  scanf("%lld %lld", &a, &b);
  ll c = gcd(a, b);

  ll i = 2;

  int k = 0;
  ll d = c;
  while (i * i <= c) {
    if (pp[i] == 0) {
      if (c % i == 0) {
        while (d % i == 0)
          d /= i;
        k++;
      }
      ll j = 2;
      while (i * j * i * j <= c) {
        pp[i * j] = 1;
        j++;
      }
    }
    i++;
  }
  // printf("%lld\n", d);
  if (d == 1)
    printf("%d\n", k + 1);
  else if (k == 0) {
    if (c == 2)
      printf("2\n");
    else
      printf("1\n");
  } else
    printf("%d\n", k + 2);
  return 0;
}
