#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int acs(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
} /* 1,2,3,4.. */
int des(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
} /* 8,7,6,5.. */
int cmp_char(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
} /* a,b,c,d.. */
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define MAX 5001
#define MOD 1000000007

typedef long long int lli;

int cmp_str(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
} /* aaa,aab.. */

int main(void) {
  char s[MAX];
  int k;
  scanf("%s %d", s, &k);

  int cnt = 0;
  char *sub[MAX * 5];
  int n = strlen(s);
  for (int b = 0; b < n; b++) {
    for (int e = b; e < n && e < b + k; e++) {
      int len = e - b + 1;
      sub[cnt++] = strndup(s + b, len);
    }
  }

  qsort(sub, cnt, sizeof(char **), cmp_str);

  int ki = 1;
  for (int ci = 0; ci < cnt; ci++) {
    if (ki == k) {
      printf("%s\n", sub[ci]);
      break;
    }
    if (strcmp(sub[ci], sub[ci + 1]) == 0)
      continue;
    ki++;
  }
  return 0;
}
