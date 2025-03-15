#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define INF 1 << 31 - 1
#define LNF 9223372036854775807
#define PI 3.14159265358979
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define FOR(i, a, n) for (i = a; i < n; i++)
#define MOD 1000000007
//#define MOD 998244353
#define NUM 200010

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
int abs(int a) {
  if (a < 0)
    return -a;
  return a;
}
int dup(int a, int d) {
  if (a % d == 0)
    return a / d;
  else
    return a / d + 1;
}
int mod(int a, int m) {
  if (a < 0)
    return a % m + m;
  else
    return a % m;
}

void swapl(ll *a, ll *b) {
  ll tmp = *a;
  *a = *b;
  *b = tmp;
}
ll absl(ll a) {
  if (a < 0)
    return -a;
  return a;
}
ll dupl(ll a, ll d) {
  if (a % d == 0)
    return a / d;
  else
    return a / d + 1;
}
ll modl(ll a, ll m) {
  if (a < 0)
    return a % m + m;
  else
    return a % m;
}

ll GCD(ll a, ll b) {
  ll c = 1, tmp = MAX(a, b);
  b = MIN(a, b);
  a = tmp;
  while (c != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

ll factorial(ll n, ll m) { return n < m ? 1 : n * factorial(n - 1, m); }

int upll(const void *a, const void *b) {
  return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0;
}
int downll(const void *a, const void *b) {
  return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0;
}
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }

// ll dp[]

int main() {
  ll A[3][3];
  ll n, b[10];
  ll check = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%lld", &A[i][j]);
    }
  }
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", b + i);
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (A[i][j] == b[k])
          A[i][j] = -1;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    if ((A[i][0] & A[i][1] & A[i][2]) == -1)
      check++;
    if ((A[0][i] & A[1][i] & A[2][i]) == -1)
      check++;
  }
  if ((A[0][0] & A[1][1] & A[2][2]) == -1)
    check++;
  if ((A[2][0] & A[1][1] & A[0][2]) == -1)
    check++;

  if (check != 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}