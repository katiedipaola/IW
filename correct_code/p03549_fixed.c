#include <math.h>
#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", (int)(((n - m) * 100 + m * 1900) * pow(2, m)));
}