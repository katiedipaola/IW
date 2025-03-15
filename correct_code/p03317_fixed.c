#include <stdio.h>

int main() {
  int N, K;
  int work;
  int a[100000];
  int i;
  scanf("%d %d", &N, &K);
  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  if (N <= K) {
    printf("1\n");
  } else if (N > K) {
    work = (N - K) / (K - 1);
    if ((N - K) % (K - 1) != 0) {
      work += 1;
    }
    printf("%d\n", work + 1);
  }
  return 0;
}
