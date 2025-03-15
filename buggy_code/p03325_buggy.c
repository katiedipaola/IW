#include <stdio.h>

int main(void) {

  int N;
  scanf("%d", &N);

  int *a;
  a = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  int ans;
  for (int i = 0; i < N; i++) {
    while (a[i] % 2 == 0) {
      a[i] = a[i] / 2;
      ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
