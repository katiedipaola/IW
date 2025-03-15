#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  int hoge = 1;
  int i;
  for (i = 0; i < n; i++) {
    hoge = hoge * 2 < hoge + k ? hoge * 2 : hoge + k;
  }
  printf("%d", hoge);
  printf("\n");
  return 0;
}