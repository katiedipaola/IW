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
        ans[i - 1] = 1;
        ball++;
      }
      break;
    }
    int count = 0;
    for (int j = 1;; j++) {
      if (i * j - 1 >= N)
        break;
      count += ans[i * j - 1];
    }
    if (count % 2 != a[i - 1]) {
      ans[i - 1] = 1;
      ball++;
    }
  }

  printf("%d\n", ball);
  for (int i = 0; i < N; i++) {
    if (ans[i] == 1) {
      ball--;
      printf("%d", i + 1);
      if (ball == 0)
        printf("\n");
      else
        printf(" ");
    }
  }

  /* printf("\n"); */
  /* for (int i = 0; i < N; i++) { */
  /*   printf("%d ", ans[i]); */
  /* } */

  return 0;
}