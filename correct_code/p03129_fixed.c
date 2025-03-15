#include <stdio.h>

int main() {
  int i, N, K, num = 0;

  scanf("%d", &N);
  scanf("%d", &K);

  for (i = 1; i <= N; i++) {
    if (i % 2 != 0) {
      num++;
    }
  }

  if (num >= K) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}