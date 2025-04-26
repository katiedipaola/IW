#include <stdio.h>
int main() {
  int N, X, D = 0, count = 0;
  int L[100];
  L[0] = 0;
  scanf("%d %d", &N, &X);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &L[i]);
  }
  for (int i = 1; i <= N; i++) {
    D += L[i - 1];
    if (D <= X) {
      count++;
    } else {
      break;
    }
  }
  printf("%d\n", count);
  return 0;
}