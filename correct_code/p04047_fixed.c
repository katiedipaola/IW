#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);
  int L[2 * N];
  for (int i = 0; i < 2 * N; i++) {
    scanf("%d", &L[i]);
  }
  int M = 0;
  for (int i = 0; i < 2 * N - 1; i++) {
    for (int j = 0; j < 2 * N - 1; j++) {
      if (L[j] > L[j + 1]) {
        int z;
        z = L[j + 1];
        L[j + 1] = L[j];
        L[j] = z;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    M += L[2 * i];
  }
  printf("%d\n", M);
  return 0;
}