#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

long long dist(long long M, long long N) {
  long long D;
  if (M < N) {
    D = M;
    M = N;
    N = D;
  }
  if (N == 0) {
    return 0;
  }
  D = (M / N) * 2 * N;
  if (M % N == 0)
    D -= 1;
  return D + dist(N, M % N);
}

int main() {
  long long L, N, P, X;
  scanf("%lld%lld", &N, &X);
  if (2 * X == N)
    L = 3 * X;
  else
    L = N + dist(X, N - X);
  /*	if (2*X < N) {
                  L = X + (N-X) + X;
                  P = N-2*X;
                  L += X+dist(P,X);
          } else if (2*X == N) {
                  L = 3 * X;
          } else {
                  L = X;
                  L += (N-X) + dist(X,N-X);
          }*/

  printf("%lld\n", L);
  return 0;
}
