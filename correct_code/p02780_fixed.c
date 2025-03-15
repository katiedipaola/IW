#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N, K;
  double p[200010];
  int num;
  double sum = 0;
  double ans = 0;

  scanf("%d", &N);
  scanf("%d", &K);

  for (int i = 0; i < N; i++) {
    scanf("%d", &num);
    p[i] = (num + 1) * (num / 2.0) / num;
  }

  sum = 0;
  for (int i = 0; i < K; i++) {
    sum += p[i];
  }
  ans = sum;

  for (int i = 1; i <= N - K; i++) {
    sum = sum - p[i - 1] + p[i + K - 1];
    if (ans < sum) {
      ans = sum;
    }
  }

  printf("%lf", ans);

  return 0;
}