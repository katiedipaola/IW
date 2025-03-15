#include <stdio.h>

int N, M; // a
int a, b, c;
int i;
int sum, max;

int main() {
  scanf("%d %d", &N, &M);

  for (i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    c = N - a;
    if (c > 0) {
      sum += c;
    }
    if (c >= max) {
      max = c;
    }
  }
  printf("%d\n", sum - max);

  return 0;
}