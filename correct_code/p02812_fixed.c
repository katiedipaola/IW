#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int ll;
typedef unsigned long long int ull;
ll gcd(ll x, ll y) {
  if (!y)
    return x;
  return gcd(y, x % y);
}
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
double to_deg(double r) { return r * 180.0 / (atan(1.0) * 4.0); }
// Sieve of Eratosthenes
int isprime(int x) {
  if (x == 2)
    return 1;
  if (x % 2 == 0)
    return 0;
  for (int i = 3; i <= sqrt((double)x); i++)
    if (x % i == 0)
      return 0;
  return 1;
}
int asc_cmp(const void *X, const void *Y) {
  int x = *(int *)X, y = *(int *)Y;
  if (x < y)
    return -1;
  else if (x == y)
    return 0;
  else
    return 1;
}
int desc_cmp(const void *X, const void *Y) {
  int x = *(int *)X, y = *(int *)Y;
  if (x < y)
    return 1;
  else if (x == y)
    return 0;
  else
    return -1;
}
typedef struct {
  int x;
  int y;
} pair_t;

int main() {
  int n;
  scanf("%d", &n);
  char str[100];
  scanf("%s", str);
  int cnt = 0;
  for (int i = 0; i < n - 2; i++) {
    if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C')
      cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}