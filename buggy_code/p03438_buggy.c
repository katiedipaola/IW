#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define P 1000000007

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(void) {
  int n, i;
  int a[10000], b[10000];
  long A = 0, B = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    A += a[i];
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    B += b[i];
  }
  long c = 0, d = 0;
  for (i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      c += (b[i] - a[i] + 1) / 2;
    }
    if (a[i] > b[i]) {
      d += a[i] - b[i];
    }
  }
  puts(c >= d ? "Yes" : "No");
}
