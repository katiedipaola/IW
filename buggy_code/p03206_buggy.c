#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int int64;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > (0) ? (a) : -(a))

void run(void) {
  int d;
  scanf("%d", &d);
  printf("Christmas");
  d -= 22;
  while (d > 0) {
    d--;
    printf(" Eve");
  }
  printf("\n");
}

int main(void) {
  run();
  return 0;
}
