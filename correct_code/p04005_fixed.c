#include <stdio.h>

int main() {
  long long int A, B, C, min;
  scanf("%lld %lld %lld", &A, &B, &C);
  if (A % 2 && B % 2 && C % 2) {
    min = A * B;
    if (A * C < min)
      min = A * C;
    if (C * B < min)
      min = C * B;
    printf("%lld\n", min);
  } else {
    printf("0\n");
  }
}