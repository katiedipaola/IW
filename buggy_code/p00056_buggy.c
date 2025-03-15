#include <math.h>
#include <stdio.h>
#define N 50000

int main() {
  int i, j, n;
  int prime[N];
  for (i = 0; i < N; i++) {
    prime[i] = 1;
  }
  prime[0] = 0;
  for (i = 1; i < (int)sqrt(N); i++) {
    if (prime[i] == 1) {
      for (j = i + 1; (i + 1) * j <= N; j++) {
        prime[(i + 1) * j - 1] = 0;
      }
    }
  }
  while (scanf("%d", &n)) {
    if (n == 0)
      break;
    int cnt = 0;
    for (i = 1; i < n; i++) {
      if (i > n / 2)
        break;
      if (prime[i] == 1)
        if (prime[n - (i + 2)] == 1)
          cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}