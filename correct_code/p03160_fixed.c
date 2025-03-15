#include <stdio.h>
int abs(int);
int main() {
  long n;
  scanf("%ld", &n);
  int h[n], dp[n];
  for (long i = 0; i < n; i++) {
    scanf("%ld", &h[i]);
  }
  for (long i = 0; i < n; i++) {
    if (i == 0) {
      dp[i] = 0;
      //      printf("%ld\n",dp[i]);
    }
    if (i == 1) {
      dp[i] = abs(h[1] - h[0]);
      //      printf("%ld\n",dp[i]);
    }
    if (i > 1) {
      if (dp[i - 2] + abs(h[i] - h[i - 2]) < dp[i - 1] + abs(h[i] - h[i - 1])) {
        dp[i] = dp[i - 2] + abs(h[i] - h[i - 2]);
        //        printf("%ld\n",dp[i]);
      } else {
        dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        //        printf("%ld\n",dp[i]);
      }
    }
  }
  printf("%ld\n", dp[n - 1]);
  return 0;
}
int abs(int x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}
