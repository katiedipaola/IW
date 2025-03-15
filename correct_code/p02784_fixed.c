#include <stdio.h>

int main() {
  long long int a, b, c[200000], i, sum = 0;
  scanf("%lld %lld", &a, &b);

  for (i = 0; i < b; i++) {
    scanf("%lld", &c[i]);
    sum = sum + c[i];
  }

  if (a - sum <= 0) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}
