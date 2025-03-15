// A - Kyu in AtCoder
// Hiia
#include <stdio.h>
#include <stdlib.h> //rannsuu, zettaichi(absolute)
#include <time.h>
// srand((unsigned int) time(0));
#include <math.h>   //koudona keisann
#include <string.h> //hairetsu
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))
typedef long long ll;
//#define N 998244353
#define pi 3.1415926535897932384626433832

int gcd(int m, int n) {
  if ((0 == m) || (0 == n))
    return 0;
  while (m != n)
    if (m > n)
      m = m - n;
    else
      n = n - m;
  return m;
}
int lcm(int m, int n) {
  if ((0 == m) || (0 == n))
    return 0;
  return (m * n / gcd(m, n));
}
int fact(int x) {
  if (x == 1)
    return (x);
  else
    return (x * fact(x - 1));
} // Kaijou x!
int ruijou(int base, int exponent) {
  int i, answer = 1;
  i = exponent;
  while (i != 0) {
    answer = answer * base;
    --i;
  }
  return answer;
} // ruijou base^exponent

long long int llgcd(long long int m, long long int n) {
  if ((0 == m) || (0 == n))
    return 0;
  while (m != n)
    if (m > n)
      m = m - n;
    else
      n = n - m;
  return m;
}
long long int lllcm(long long int m, long long int n) {
  if ((0 == m) || (0 == n))
    return 0;
  return (m * n / llgcd(m, n));
}
long long int llfact(long long int x) {
  if (x == 1)
    return (x);
  else
    return (x * llfact(x - 1));
} // Kaijou
int llruijou(long long int base, long long int exponent) {
  long long int i, answer = 1;
  i = exponent;
  while (i != 0) {
    answer = answer * base;
    --i;
  }
  return answer;
} // ruijou base^exponent

int main() {
  int x;
  scanf("%d", &x);
  if (400 <= x && x <= 599) {
    printf("8\n");
  }
  if (600 <= x && x <= 799) {
    printf("7\n");
  }
  if (800 <= x && x <= 999) {
    printf("6\n");
  }
  if (1000 <= x && x <= 1199) {
    printf("5\n");
  }
  if (1200 <= x && x <= 1399) {
    printf("4\n");
  }
  if (1400 <= x && x <= 1599) {
    printf("3\n");
  }
  if (1600 <= x && x <= 1799) {
    printf("2\n");
  }
  if (1800 <= x && x <= 1999) {
    printf("1\n");
  }

  return 0;
}
