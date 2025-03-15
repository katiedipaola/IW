#include <stdio.h>
#include <stdlib.h>

int up(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), up);
  int x, y, z;
  x = a[0];
  i = 1;
  int ans = 1;
  int flag = 1;
  int xn = 0;
  int yn = 0;
  int zn = 0;
  while (i < n) {
    if (x != a[i]) {
      y = a[i];
      xn = i;
      break;
    } else {
      i++;
    }
  }
  if (i == n && flag) {
    y = x;
    z = x;
    flag = 0;
  }
  while (i < n) {
    if (y != a[i]) {
      z = a[i];
      yn = i - xn;
      break;
    } else {
      i++;
    }
  }
  if (i == n && flag) {
    yn = n - xn;
    if (x ^ y == x && x ^ x == y && xn == yn * 2) {
      z = x;
    } else if (x ^ y == y && y ^ y == x && yn == xn * 2) {
      z = y;
    } else {
      ans = 0;
    }
    flag = 0;
  }
  while (i < n) {
    if (z != a[i]) {
      zn = i - yn - xn;
      break;
    } else {
      i++;
    }
  }
  if (i == n && flag) {
    zn = n - yn - xn;
    // printf("%d %d %d\n", xn, yn, zn);
    if ((xn != yn) || (yn != zn)) {
      ans = 0;
    }
  }
  if (i != n) {
    ans = 0; // 4種類以上はアウト
  }
  if (ans) {
    // printf("%d %d %d\n", x, y, z);///////////
    if (x ^ y != z) {
      ans = 0;
    }
  }
  if (ans) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
