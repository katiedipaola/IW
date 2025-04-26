#include <stdio.h>

int main(void) {
  long long int N;
  scanf("%lld", &N);

  int i;
  long long int sum = 0;
  for (i = 0; i < N; i++) {
    int n;
    scanf("%lld", &n);
    sum += n;
  }
  printf("%lld\n", sum / N);

  return 0;
}
