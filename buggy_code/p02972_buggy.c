#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);

  int a[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  int ans[N];
  for (int i = 0; i < N; i++) {
    ans[i] = 0;
  }

  int ball = 0;
  for (int i = N; i >= 1; i--) {
    if (i == 1) {
      if (ball % 2 != a[i - 1]) {
        a[i - 1] = 1;
        ball++;
      }
      break;
    }
    int count = 0;
    for (int j = 1;; j++) {
      if (i * j > N)
        break;
      count += a[i * j - 1];
    }
    if (count % 2 != a[i - 1]) {
      ans[i - 1] = 1;
      ball++;
    }
  }

  printf("%d\n", ball);
  for (int i = 0; i < N; i++) {
    if (a[i] == 1) {
      ball--;
      printf("%d", i + 1);
      if (ball == 0)
        printf("\n");
      else
        printf(" ");
    }
  }

  return 0;
}