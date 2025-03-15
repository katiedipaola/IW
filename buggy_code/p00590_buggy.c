#include <math.h>
#include <stdio.h>
#define MAX 10000

int main(int argc, char const *argv[]) {
  int i, j, n, count = 0;
  int prime[MAX];

  for (i = 0; i <= MAX; i++)
    prime[i] = 1;          // i == 1 -> prime
  prime[0] = prime[1] = 0; // i == 0 -> !prime

  for (i = 2; i < sqrt(MAX); i++) {
    if (prime[i] == 1) {
      for (j = i; i * j <= MAX; j++) {
        prime[i * j] = 0;
      }
    }
  }

  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++)
      if (prime[i] + prime[(n + 1) - i] == 2)
        count++;
    printf("%d\n", count);
  }

  return 0;
}