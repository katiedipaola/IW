#include <stdio.h>

int main() {
  long int N, K, S[101], B, i, j, flag;

  while (0 <= scanf("%ld%ld", &N, &K)) {
    if (N == 0 && K == 0) {
      break;
    }

    for (i = 1; i <= K; i++) {
      scanf("%ld", &S[i]);
    }

    for (i = 1; i <= N; i++) {
      for (j = 1; j <= K; j++) {
        scanf("%ld", &B);
        S[j] = S[j] - B;
      }
    }

    flag = 0;
    for (i = 1; i <= K; i++) {
      if (S[i] < 0) {
        flag = 1;
      }
    }

    if (flag == 1) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}