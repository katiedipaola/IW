#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);
  int a[N], color[9];
  for (int i = 0; i < 9; i++) {
    color[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    int k = a[i] / 400;
    if (k > 8) {
      k = 8;
    }
    color[k]++;
  }

  int min = 0;
  for (int i = 0; i < 8; i++) {
    if (color[i] != 0) {
      min++;
    }
  }

  int max = min + color[8];
  if (max > 8) {
    max = 8;
  }

  printf("%d %d\n", min, max);

  return 0;
}
