/*
AizuOnline A2150
Title Matuzaki
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
//#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
#define PRIME_MAX 101197 // from 10^5 100th prime
// Global data section
int N, P;
//
int prime_f[PRIME_MAX + 1];

int prime_table[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,
                     37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,
                     83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137,
                     139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
                     197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                     263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};
int prime_over_N[100];
void make_furui() {
  int i, j, p;

  prime_f[0] = 0;
  prime_f[1] = 0;
  for (i = 2; i <= PRIME_MAX + 1; i++)
    prime_f[i] = 1;
  for (i = 0; i < sizeof(prime_table) / sizeof(int); i++) {
    p = prime_table[i];
    prime_f[p] = 1;
    for (j = 2; prime_table[i] * j < PRIME_MAX; j++)
      prime_f[p * j] = 0;
  }
}
int isprime(int n) { return (prime_f[n]); }
void make_prime_table(int n, int p) {
  int i, j;

  n++;
  for (j = 0; p > 0; n++) {
    if (isprime(n)) {
      prime_over_N[j] = n;
      p--;
      j++;
    }
  }
}
solve(int n, int p) {
  int i, r2, j, k, s;

  make_prime_table(n, p);

  r2 = prime_over_N[0] + prime_over_N[1];
  if (p == 1)
    return (prime_over_N[0] * 2);
  else if (p == 2)
    return (r2);

  p -= 2;
  for (i = r2 + 1; p; i++) {

    for (j = 0; j < P; j++) {
      for (k = 0; k <= j; k++) {
        s = prime_over_N[j] + prime_over_N[k];
        // printf("P1P2=%d P=%d\n",prime_over_N[j],prime_over_N[k]);
        // printf("S=%d \n",s);
        if (s < i)
          continue;
        if (s == i)
          p--;
        break;
      }
      if (p == 0)
        goto END;
    }
  }
END:
  return (i);
}
//
main() {
  make_furui();

  while (scanf("%d %d", &N, &P) && (!(N == -1 && P == -1))) {
    printf("%d\n", solve(N, P));
  }
  return (0);
}