#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> //random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h> //sleep()

#define rep(i, n) for (int i = 0; i < ((int)n); i++)
#define REP(i, n) for (int i = 0; i <= ((int)n); i++)
#define srep(i, a, n) for (int i = a; i < ((int)n); i++)
#define SREP(i, a, n) for (int i = a; i <= ((int)n); i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define RREP(i, n) for (int i = n; i >= 0; i--)
#define INF 1000000000
const int mod = INF + 7;

int pow_mod(int a, int p) {
  int digit = 0;
  int ans = 1;
  int temp = a;

  while (p >= (1 << digit)) {
    if (p & (1 << digit)) {
      ans = (long)ans * temp % mod;
    }
    temp = (long)temp * temp % mod;
    digit++;
  }
  return ans;
}

int combination(int n, int r, int *factorial, int *factorial_p) {
  int ans =
      ((long)factorial[n] * factorial_p[n - r] % mod) * factorial_p[r] % mod;
  return ans;
}

int main() {
  char buf[1024];
  int N, K;

  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d %d", &N, &K);

  int *factorial = (int *)malloc(sizeof(int) * (N + 1));
  factorial[0] = 1;
  srep(i, 1, N + 1) { factorial[i] = (long)factorial[i - 1] * i % mod; }

  int *factorial_p = (int *)malloc(sizeof(int) * (N + 1));
  rep(i, N + 1) { factorial_p[i] = pow_mod(factorial[i], mod - 2); }

  srep(i, 1, K + 1) {
    if (N - K + 1 < i) {
      printf("%d\n", 0);
    } else {
      int ans = (long)combination(K - 1, i - 1, factorial, factorial_p) *
                combination(N - K + 1, i, factorial, factorial_p) % mod;
      printf("%d\n", ans);
    }
  }

  return 0;
}
