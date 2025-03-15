#include <stdio.h>

int main(void) {

  int N;
  int answer;

  scanf("%d", &N);

  int V[N];
  int C[N];
  int sa[N];

  int i;

  for (i = 0; i < N; i++) {
    scanf("%d", &V[i]);
  }

  for (i = 0; i < N; i++) {
    scanf("%d", &C[i]);
  }

  for (i = 0; i < N; i++) {
    sa[i] = V[i] - C[i];
  }

  for (i = 0; i < N; i++) {
    if (sa[i] >= 0) {
      answer += sa[i];
    }
  }

  printf("%d\n", answer);

  return 0;
}