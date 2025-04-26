#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000
#define MAX 1000000000000000000

int main(void) {
  unsigned long long n, a[N], ans = 1;
  unsigned long long i, j = 0, k = 0;
  unsigned long long ans_arry[N];

  scanf("%llu", &n);

  for (i = 0; i < n; i++) {
    scanf("%llu", &(a[i]));

    if (a[i] == 0) {
      puts("0");
      return 0;
    }
  }

  for (i = 0; i < n; i++) {
    if (ans >= MAX / a[i]) {
      puts("-1");
    }

    ans *= a[i];
  }

  /*
  for (i = 0; i < n; i++) {
      if (a[i] > 1000000000000000000) {
          puts("-1");
      }

      if (a[i] > 1000000000) {
          ans_arry[j] = ans;
          j++;

          ans_arry[j] = a[i];
          j++;
          ans = 1;
      } else {
          ans = ans * a[i];
      }

      if (ans > 1000000000000000000) {
          puts("-1");
          return 0;
      }

      if (ans > 1000000000) {
          ans_arry[j] = ans;
          j++;
          ans = 1;
      }
  }

  if (ans != 1) {
      ans_arry[j] = ans;
      j++;
  }

  for (i = 0; i < j; i++) {
      if (ans_arry[i] > 1000000000) {
          k++;
      }

      if (k >= 2) {
          puts("-1");
          return 0;
      }
  }

  ans = 1;
  for (i = 0; i < j; i++) {
      ans *= ans_arry[i];

      if (ans > 1000000000000000000) {
          puts("-1");
          return 0;
      }
  }
  */

  printf("%llu", ans);

  return 0;
}
