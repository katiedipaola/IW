#include <stdio.h>
int main() {
  long long int a, i = 1, b = 100;
  scanf("%lld", &a);

  while (1) {
    b = b * 1.01;
    if (b >= a) {
      printf("%lld\n", i);
      return 0;
    }
    i++;
  }
}
