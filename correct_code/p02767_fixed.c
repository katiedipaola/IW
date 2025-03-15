#include <stdio.h>

int main(void) {
  int a = 0, b = 0, i = 0, j = 0, N = 0, X = 0, Xmin = 0, answer = 0, Y = 0;

  scanf("%d", &N);

  int A[N];

  for (i = 0; i < N; i++) {
    scanf("%d", &a);
    A[i] = a;
  }

  for (i = 0; i < N; i++) {
    b = A[i];
    Y = b - 1;
    Xmin = Xmin + Y * Y;
  }

  answer = 1;

  X = 0;
  i = 0;

  for (j = 1; j < 101; j++) {
    for (i = 0; i < N; i++) {
      b = A[i];
      Y = b - j;
      X = X + Y * Y;
    }

    if (X < Xmin) {
      Xmin = X;
      answer = j;
    }

    X = 0;
  }

  printf("%d", Xmin);

  return 0;
}
