#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region 定義
#define i_cin(X) scanf("%d", &X)
#define i_cin2(X, Y) scanf("%d %d", &X, &Y)
#define i_cin4(X, Y, Z, W) scanf("%d %d %d %d", &X, &Y, &Z, &W)
#define i_cin3(X, Y, Z) scanf("%d %d %d", &X, &Y, &Z)
#define l_cin(X) scanf("%ld", &X)
#define f_cin(X) scanf("%f", &X)
#define l_cin2(X, Y) scanf("%ld %ld", &X, &Y)
#define s_cin(X) scanf("%s", &X)
#define ll_cin(X) scanf("%lld", &X)

#define i_cout(X) printf("%d\n", X)
#define f_cout(X) printf("%g\n", X)
#define i_cout2(X, Y) printf("%d %d\n", X, Y)
#define l_cout(X) printf("%ld\n", X)
#define s_cout(X) printf("%s\n", X)
#define ll_cout(X) printf("%lld\n", X)

typedef long long ll;
#define rept(x, s, n) for (int x = s; x < n; x++)

#define S_RTN(S)                                                               \
  s_cout(S);                                                                   \
  return 0

#define _itoa(A, N) sprintf(A, "%d", N);

int i_cins(int n, int *A);
int l_cins2(int n, long *A, long *B);
int s_dsort(const void *a, const void *b);
int s_asort(const void *a, const void *b);

int _gcd(int a, int b);
int _swp(int *a, int *b);
int _cknum(char *a, int n);
int _atoi(char *s, int len);

int s_asorts(const void *a, const void *b);

//昇順
int s_asorts(const void *a, const void *b) {
  return (strcmp((char *)a, (char *)b));
}
int s_dsort(const void *a, const void *b) { return (*(int *)b - *(int *)a); }
int s_asort(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int l_cins2(int n, long *a, long *b) {
  int i;
  rept(i, 0, n) { l_cin2(*(a + i), *(b + i)); }
  return 0;
}
int i_cins(int n, int *a) {
  int i;
  for (i = 0; i < n; i++) {
    i_cin(*(a + i));
  }

  return 0;
}
int _gcd(int a, int b) {
  int r, tmp;
  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  r = a % b;
  while (r) {
    if (!r)
      break;
    a = b;
    b = r;
    r = a % b;
  }
  return (b);
}

long _max(long a, long b) { return a > b ? a : b; }
long _min(long a, long b) { return a < b ? a : b; }
int _swp(int *a, int *b) {
  int tmp;
  tmp = *b;
  *b = *a;
  *a = tmp;
  return 0;
}

int main() {
  char a[4];
  scanf("%s", a);
  if (a[1] == 'B') {
    printf("ARC");
    return 0;
  } else {
    printf("ABC");
  }
}