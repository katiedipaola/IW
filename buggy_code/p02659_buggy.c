#include <stdio.h>

int main() {
  long long int a;
  double b;

  scanf("%lld %llf", &a, &b);

  printf("%lld", (a * (long long)(b * 100 + 0.5) / 100));
  return 0;
}
