#include <stdio.h>
int main(void) {
  int i, n = 1;
  long long int N;
  scanf("%lld", &N);

  for (n = 1; n * n <= N; n++) {
  }

  printf("%d\n", (n - 1) * (n - 1));

  return 0;
}
