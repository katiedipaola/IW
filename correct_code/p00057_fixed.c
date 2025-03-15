#include <stdio.h>

int main() {
  int n, roop, area = 1;

  while (scanf("%d", &n) != EOF) {

    for (roop = 1; roop <= n; roop++) {
      area += roop;
    }

    printf("%d\n", area);
    area = 1;
  }

  return 0;
}