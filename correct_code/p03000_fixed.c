#include <stdio.h>
int main() {
  int N, X, D = 0, count = 0;
  int L[101];
  L[0] = 0;
  scanf("%d %d", &N, &X);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &L[i]);
  }
  for (int i = 1; i <= N; i++) {
    D += L[i];
    if (D <= X) {
      count++;
    } else {
      break;
    }
  }
  printf("%d\n", count + 1);
  return 0;
}
