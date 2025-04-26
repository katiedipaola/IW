/*

*/

#include <stdio.h>

int max = 10000000;

short prime[10000000];

void make_prime() {
  int i, p, n;
  for (i = 0; i <= max; i++) {
    prime[i] = 1;
  }
  prime[0] = 0;
  prime[1] = 0;
  for (p = 2; p <= max; p++) {
    if (prime[p]) {
      for (n = p + p; n <= max; n += p) {
        prime[n] = 0;
      }
    }
  }
}

int main() {
  short n;
  make_prime();
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    } else if (n >= 13 && n <= 10000000) {
      while (1) {
        if (prime[n]) {
          if (prime[n - 2]) {
            if (prime[n - 6]) {
              if (prime[n - 8]) {
                printf("%d\n", n);
                break;
              }
            }
          }
        }
        n--;
      }
    }
  }
  return 0;
}