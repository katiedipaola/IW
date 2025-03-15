#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int n, m = -1, c = 1, f = 0;
  scanf("%d", &n);
  while (1) {
    if (n % 10 == m)
      c++;
    else {
      c = 1;
      m = n % 10;
    }
    if (c == 3) {
      f = 1;
      break;
    }
    n /= 10;
  }
  if (f == 1)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
