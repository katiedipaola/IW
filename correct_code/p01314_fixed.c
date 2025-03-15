/*
AizuOnline A2197
Title
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
//#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
// Global data section
int n;
//
main() {
  int i, c;

  while (EOF != scanf("%d", &n) && n) {
    c = 0;
    for (i = 2; i * (i + 1) <= 2 * n; i++)
      if (((n - (i - 1) * i / 2) % i) == 0)
        c++;
    printf("%d\n", c);
  }
  return (0);
}