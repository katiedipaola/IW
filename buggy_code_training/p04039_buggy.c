// set many funcs template
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int zt(int a, int b) { return max(a, b) - min(a, b); }
int round(int a, int b) {
  if ((a % b) * 2 >= b) {
    return (a / b) + 1;
  }
  return a / b;
}
int ceil(int a, int b) {
  if (a % b == 0) {
    return a / b;
  }
  return (a / b) + 1;
}
int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int lcm(int a, int b) {
  int c = gcd(a, b);
  a /= c;
  return a * b;
}
int nCr(int a, int b) {
  int i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= (a + 1 - i);
    r /= i;
  }
  return r;
}
int fact(int a) {
  int i, r = 1;
  for (i = 1; i <= a; i++) {
    r *= i;
  }
  return r;
}
int pow(int a, int b) {
  int i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= a;
  }
  return r;
}
long long llmax(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
long long llmin(long long a, long long b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long llzt(long long a, long long b) { return llmax(a, b) - llmin(a, b); }
long long llround(long long a, long long b) {
  if ((a % b) * 2 >= b) {
    return (a / b) + 1;
  }
  return a / b;
}
long long llceil(long long a, long long b) {
  if (a % b == 0) {
    return a / b;
  }
  return (a / b) + 1;
}
long long llgcd(long long a, long long b) {
  long long c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
long long lllcm(long long a, long long b) {
  long long c = llgcd(a, b);
  a /= c;
  return a * b;
}
long long llnCr(long long a, long long b) {
  long long i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= (a + 1 - i);
    r /= i;
  }
  return r;
}
long long llfact(long long a) {
  long long i, r = 1;
  for (i = 1; i <= a; i++) {
    r *= i;
  }
  return r;
}
long long llpow(long long a, long long b) {
  long long i, r = 1;
  for (i = 1; i <= b; i++) {
    r *= a;
  }
  return r;
}
double dbmax(double a, double b) {
  if (a > b) {
    return a;
  }
  return b;
}
double dbmin(double a, double b) {
  if (a < b) {
    return a;
  }
  return b;
}
double dbzt(double a, double b) { return dbmax(a, b) - dbmin(a, b); }
int sortfncsj(const void *a, const void *b) {
  if (*(int *)a > *(int *)b) {
    return 1;
  }
  if (*(int *)a == *(int *)b) {
    return 0;
  }
  return -1;
}
int sortfnckj(const void *a, const void *b) {
  if (*(int *)a < *(int *)b) {
    return 1;
  }
  if (*(int *)a == *(int *)b) {
    return 0;
  }
  return -1;
}
int llsortfncsj(const void *a, const void *b) {
  if (*(long long *)a > *(long long *)b) {
    return 1;
  }
  if (*(long long *)a == *(long long *)b) {
    return 0;
  }
  return -1;
}
int llsortfnckj(const void *a, const void *b) {
  if (*(long long *)a < *(long long *)b) {
    return 1;
  }
  if (*(long long *)a == *(long long *)b) {
    return 0;
  }
  return -1;
}
int dbsortfncsj(const void *a, const void *b) {
  if (*(double *)a > *(double *)b) {
    return 1;
  }
  if (*(double *)a == *(double *)b) {
    return 0;
  }
  return -1;
}
int dbsortfnckj(const void *a, const void *b) {
  if (*(double *)a < *(double *)b) {
    return 1;
  }
  if (*(double *)a == *(double *)b) {
    return 0;
  }
  return -1;
}

int main(void) {
  int i, m, n, k, a[131072], f[16] = {0}, ff;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    f[a[i]]++;
  }
  if (n == 0) {
    if (f[0] == 0) {
      printf("0\n");
      return 0;
    }
  }
  for (i = n; i <= 1000000; i++) {
    m = i;
    ff = 1;
    while (m) {
      if (f[m % 10]) {
        ff = 0;
      }
      m /= 10;
    }
    if (ff) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}