#include <math.h>
#include <stdio.h>

int main() {

  long n;
  scanf("%ld", n);
  long a = 1, b;
  long ans = n + 60;
  while ((long)sqrt(n) >= a) {
    b = n / a;
    if (a * b == n && a + b - 2 < ans) {
      ans = a + b - 2;
    }
    a++;
  }
  printf("%ld", ans);
}
