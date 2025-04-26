#include <stdio.h>
#define min(a, b) a < b ? a : b

int main() {
  int n;
  int i, j;
  int c;
  int a[1000001];
  int b[1000001];

  for (i = 0; i < 1000001; i++) {
    a[i] = i;
    b[i] = i;
  }

  for (i = 3, c = 4; c < 1000001; i++) {
    for (j = c; j < 1000001; j++) {
      a[j] = min(a[j], a[j - c] + 1);
    }
    if (c % 2) {
      for (j = a; j < 1000001; j++) {
        b[j] = min(b[j], b[j - c] + 1);
      }
    }
    c = i * (i + 1) * (i + 2) / 6;
  }

  while (scanf("%d", &n), n) {
    printf("%d %d\n", a[n], b[n]);
  }

  return 0;
}