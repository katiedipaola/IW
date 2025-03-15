#include <stdio.h>
int prime[2000];
int c;
int count;
int isPrime(int n) {
  int i;
  if (n == 2)
    return 1;
  if (n == 1)
    return 0;
  if (!(n % 2))
    return 0;
  for (i = 1; i < c; i++) {
    if (n == prime[i])
      return 1;
    if (!(n % prime[i]))
      return 0;
  }
  for (i = prime[c - 1]; i < n / 2; i += 2) {
    if (!(n % i))
      return 0;
  }
  return 1;
}
void search(int n, int i, int sum) {
  int j;
  if (sum + prime[i] == n) {
    count++;
    return;
  }
  if (sum + prime[i] > n)
    return;
  sum += prime[i];
  search(n, i + 1, sum);
}
int main() {
  int i, n;
  prime[0] = 2;
  prime[1] = 3;
  prime[2] = 5;
  prime[3] = 7;
  prime[4] = 11;
  c = 5;
  for (i = 13; i < 10000; i += 2) {
    if (isPrime(i)) {
      prime[c] = i;
      c++;
    }
  }
  for (; scanf("%d", &n) && n;) {
    count = 0;
    for (i = 0; i < c && prime[i] <= n; i++)
      search(n, i, 0);
    printf("%dz\n", count);
  }
  return 0;
}