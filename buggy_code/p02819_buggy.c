#include <stdio.h>
#define MAX 10003
int main(void) {
  int n, i, a[MAX], j;
  scanf("%d", &n);
  for (i = 0; i < MAX; i++) {
    a[i] = 0;
  }
  a[0] = 1;
  for (i = 2; i < MAX / 2; i++) {
    for (j = 2; i * j <= MAX; j++) {
      if (a[i * j - 1] == 0)
        a[i * j - 1] = 1;
    }
  }
  for (i = 0; i < MAX; i++) {
    if (a[i] == 0 && i + 1 >= n) {
      printf("%d", i + 1);
      return 0;
    }
  }
  return 0;
}