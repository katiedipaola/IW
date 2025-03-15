#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char lowcmp[26] = "abcdefghijklmnopqrstuvwxyz";
char upcmp[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
long long mod = 1000000007;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int gcd(int a, int b) {
  return min(a, b) == 0 ? max(a, b) : gcd(min(a, b), max(a, b) % min(a, b));
}
long long llmax(long long a, long long b) { return a > b ? a : b; }
long long llmin(long long a, long long b) { return a < b ? a : b; }
long long llgcd(long long a, long long b) {
  return llmin(a, b) == 0 ? llmax(a, b)
                          : llgcd(llmin(a, b), llmax(a, b) % llmin(a, b));
}
int assort(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int dessort(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int llassort(const void *a, const void *b) {
  return *(long long *)a - *(long long *)b;
}
int lldessort(const void *a, const void *b) {
  return *(long long *)b - *(long long *)a;
}
int charassort(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}
int chardessort(const void *a, const void *b) {
  return strcmp((char *)b, (char *)a);
}
int ntoi(char c) { return c - '0'; }
int ltoi(char c) { return c - 'a'; }
int utoi(char c) { return c - 'A'; }
long long ncr(int a, int b) {
  long long ans = 1;
  for (int i = 0; i < b; i++) {
    ans = ans * (a - i) / (i + 1);
  }
  return (ans);
}
long long npr(int a, int b) {
  long long ans = 1;
  for (int i = 0; i < b; i++) {
    ans = ans * (a - i);
  }
  return (ans);
}

int main(void) {
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  for (int i = 0; i < k; i++) {
    if (i % 2 == 0) {
      if (a % 2 == 1) {
        a--;
      }
      b += a / 2;
      a /= 2;
    } else {
      if (b % 2 == 1) {
        b--;
      }
      a += b / 2;
      b /= 2;
    }
  }
  printf("%d %d\n", a, b);
  return 0;
}