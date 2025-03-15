#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N, H, W, A, B, count = 0;
  if (scanf("%d %d %d", &N, &H, &W) < 3)
    N = N;
  while (N > 0) {
    if (scanf("%d %d", &A, &B) < 2)
      N = N;
    if (H <= A && W <= B)
      count++;
    N -= 1;
  }
  printf("%d", count);
}