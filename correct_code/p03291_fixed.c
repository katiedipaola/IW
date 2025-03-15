#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a) {
  a %= p;
  return a >= 0 ? a : a + p;
}

int power(int a, int N) {
  if (N == 0) {
    return 1;
  } else if (N % 2 == 0) {
    return power(MOD(a * a), N / 2);
  } else {
    return MOD(a * power(a, N - 1));
  }
}

signed main() {
  int N, i, j;
  char *S = (char *)malloc(sizeof(char) * 100002);
  scanf("%s", &S[1]);
  for (N = 1; S[N] != '\0'; N++) {
  }
  N--;
  int *dpA = (int *)malloc(sizeof(int) * (N + 1));
  int *dpAB = (int *)malloc(sizeof(int) * (N + 1));
  int *dpABC = (int *)malloc(sizeof(int) * (N + 1));
  dpA[0] = 0;
  dpAB[0] = 0;
  dpABC[0] = 0;
  for (i = 1, j = 0; i <= N; i++) {
    if (S[i] == 'A') {
      dpA[i] = MOD(dpA[i - 1] + power(3, j));
    } else if (S[i] == '?') {
      dpA[i] = MOD(3 * dpA[i - 1] + power(3, j));
      j++;
    } else {
      dpA[i] = MOD(dpA[i - 1]);
    }
  }
  for (i = 1; i <= N; i++) {
    if (S[i] == 'B') {
      dpAB[i] = MOD(dpAB[i - 1] + dpA[i - 1]);
    } else if (S[i] == '?') {
      dpAB[i] = MOD(3 * dpAB[i - 1] + dpA[i - 1]);
    } else {
      dpAB[i] = MOD(dpAB[i - 1]);
    }
  }
  for (i = 1; i <= N; i++) {
    if (S[i] == 'C') {
      dpABC[i] = MOD(dpABC[i - 1] + dpAB[i - 1]);
    } else if (S[i] == '?') {
      dpABC[i] = MOD(3 * dpABC[i - 1] + dpAB[i - 1]);
    } else {
      dpABC[i] = MOD(dpABC[i - 1]);
    }
  }
  /*	printf("dpA:\n");
          for(i = 0; i <= N; i++){
                  printf("%lld ", dpA[i]);
          }
          printf("\n");
          printf("dpAB:\n");
          for(i = 0; i <= N; i++){
                  printf("%lld ", dpAB[i]);
          }
          printf("\n");
          printf("dpABC:\n");
          for(i = 0; i <= N; i++){
                  printf("%lld ", dpABC[i]);
          }
          printf("\n");
  */
  printf("%lld\n", dpABC[N]);
  return 0;
}