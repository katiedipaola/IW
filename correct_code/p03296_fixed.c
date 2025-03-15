#include <stdio.h>
#define N 10000
int main(void) {
  int n, i, color[N], g;
  g = 0;
  for (i = 0; i < N; i++) {
    color[i] = 0;
  }
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &color[i]);
  }
  for (i = 0; i < n - 1; i++) {
    if (color[i] == color[i + 1]) {
      color[i + 1] = 10001;
      g++;
    }
  }
  printf("%d", g);
  return 0;
}
