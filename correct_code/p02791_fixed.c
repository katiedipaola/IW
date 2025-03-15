#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int P[N];

  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }
  int count = 1;
  int c = P[0];
  for (int i = 1; i < N; i++) {
    if (P[i] <= c) {
      c = P[i];
      count++;
    }
  }
  printf("%d", count);

  return 0;
}