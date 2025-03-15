#include <stdio.h>

int main(void) {
  int N, i;
  scanf("%d", &N);

  int a[N], min = 1001, max = -1;

  for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    if (a[i] > max) {
      max = a[i];
    }
    if (a[i] < min) {
      min = a[i];
    }
  }

  printf("%d", max - min);

  return 0;
}
