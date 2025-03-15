#include <stdio.h>
#include <stdlib.h>
int main() {
  int a, b, m, min = 10000000;
  int *an;
  int *bn;
  scanf("%d%d%d", &a, &b, &m);
  an = (int *)malloc(sizeof(int) * (a + 1));
  bn = (int *)malloc(sizeof(int) * (b + 1));

  for (int i = 1; i <= a; i++) {
    scanf("%d", &an[i]);
  }
  for (int i = 1; i <= b; i++) {
    scanf("%d", &bn[i]);
  }

  for (int i = 0; i < m; i++) {
    int d1, d2, d3;
    scanf("%d%d%d", &d1, &d2, &d3);
    int cost = an[d1] + bn[d2] - d3;
    if (cost < min) {
      min = cost;
    }
  }
  int bmin = bn[1], amin = an[1];
  for (int i = 2; i <= b; i++) {
    if (bn[i] < bmin) {
      bmin = bn[i];
    }
  }
  for (int i = 2; i <= a; i++) {
    if (an[i] < amin) {
      amin = an[i];
    }
  }

  if (min > amin + bmin) {
    min = amin + bmin;
  }

  printf("%d", min);
  return 0;
}