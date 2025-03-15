#include <stdio.h>

int FIND_MIN(int A, int B) {
  if (A >= B) {
    return B;
  } else {
    return A;
  }
}

int main(void) {

  int N, A, B;

  scanf("%d %d %d", &N, &A, &B);

  if (A + B <= N) {
    printf("%d %d\n", A + B, 0);
  } else {
    printf("%d %d\n", FIND_MIN(A, B), A + B - N);
  }

  return 0;
}
