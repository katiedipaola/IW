#include <stdio.h>
int main() {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  if (a == 1 && b == 1) {
    printf("1");
  } else if (a == 1 || b == 1) {
    printf("%lld", a * b - 2);
  } else {
    printf("%lld", (a - 2) * (b - 2));
  }
}