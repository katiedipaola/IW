#include <stdio.h>
int main() {
  long long int X, i = 0, sum = 0;
  scanf("%lld", &X);
  while ((sum += i) < X)
    i++;
  printf("%lld\n", i);
  return 0;
}