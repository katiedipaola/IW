#include <stdio.h>

int main() {
  long long int N;
  long long int P;
  long long int prime[100000];
  int exp[100000];
  int index = 0;
  long long int ans = 1;

  scanf("%lld %lld", &N, &P);

  for (long long int n = 2; n * n < P; n++) {
    int cnt = 0;
    while (P % n == 0) {
      P /= n;
      cnt++;
    }
    if (cnt) {
      prime[index] = n;
      exp[index++] = cnt;
    }
  }
  if (P != 1) {
    prime[index] = P;
    exp[index++] = 1;
  }

  for (int i = 0; i < index; i++)
    for (long long int j = 1; j * N <= exp[i]; j++)
      ans *= prime[i];

  printf("%lld\n", ans);

  return 0;
}
