/*
AizuOnline A0218
Title Dividing Students
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
int pe, pm, pj;
//
main() {
  int i;
  int av, avme;

  while (EOF != scanf("%d", &n) && n) {
    for (i = 0; i < n; i++) {
      scanf("%d %d %d", &pm, &pe, &pj);
      av = (pe + pm + pj) / 3;
      avme = (pe + pm) / 2;
      if (pe == 100 || pm == 100 || pj == 100 || av >= 80 || avme >= 90)
        printf("A\n");
      else if ((av >= 70) || (av >= 50 && (pe >= 80 || pm >= 80)))
        printf("B\n");
      else
        printf("C\n");
    }
  }
  return (0);
}