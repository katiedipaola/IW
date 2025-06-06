#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int int64;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > (0) ? (a) : -(a))

void run(void) {
  const int mod = 1000000007;
  int n;
  scanf("%d", &n);
  if (n == 1) {
    printf("%d\n", 1);
    return;
  }
  char s1[53];
  char s2[53];
  scanf("%s", s1);
  scanf("%s", s2);
  int64 way = 1;
  int index = 0;
  int before = 0;
  if (s1[index] == s1[index + 1]) {
    way = 6;
    index += 2;
    before = 2;
  } else {
    way = 3;
    index++;
    before = 1;
  }
  while (index < n) {
    if (index + 1 < n && s1[index] == s1[index + 1]) {
      if (before == 2) {
        way = way * 3 % mod;
      } else {
        way = way * 2 % mod;
      }
      before = 2;
      index += 2;
    } else {
      if (before == 1) {
        way = way * 2 % mod;
      }
      before = 1;
      index++;
    }
  }
  printf("%lld\n", way);
}

int main(void) {
  run();
  return 0;
}
