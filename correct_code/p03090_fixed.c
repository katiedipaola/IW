#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
  int n;
  scanf("%d", &n);
  int a[10000], b[10000], index = 0;
  int m = n;
  if (n % 2 == 0)
    m++;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (i + j != m) {
        a[index] = i;
        b[index++] = j;
      }
    }
  }
  printf("%d\n", index);
  for (int i = 0; i < index; i++) {
    printf("%d %d\n", a[i], b[i]);
  }
  return 0;
}
