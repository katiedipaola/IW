#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int k, a, b;
  int i;
  int flag = 0;

  scanf("%d", &k);
  scanf("%d %d", &a, &b);
  for (i = a; i < b; i++) {
    if (i % k == 0) {
      printf("OK");
      flag = 1;
      break;
    }
  }
  if (!flag) {
    printf("NG");
  }
  return 0;
}