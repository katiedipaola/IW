#include <stdio.h>
int main() {
  int temp, i, j, N, K, l[50], use = 0;
  scanf("%d %d", &N, &K);
  for (i = 0; i < N; i++) {
    scanf("%d", &l[i]);
  }
  for (i = 0; i < N - 1; i++) {
    for (j = N - 1; j > i; j--) {
      if (l[j - 1] > l[j]) {
        temp = l[j - 1];
        l[j - 1] = l[j];
        l[j] = temp;
      }
    }
  }
  for (i = N - 1; i > N - 1 - K; i--) {
    use += l[i];
  }
  printf("%d\n", use);
  return 0;
}
