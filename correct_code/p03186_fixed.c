#include <stdio.h>

int main() {
  long long a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);

  if (c < a + b + 1) {
    printf("%lld", b + c);
  } else {
    printf("%lld", a + 2 * b + 1);
  }
}
