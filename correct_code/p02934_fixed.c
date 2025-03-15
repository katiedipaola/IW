#include <stdio.h>

int gcd(int a, int b) {
  int tmp;
  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  int n, a[100], sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int r = a[0];
  for (int i = 1; i < n; i++) {
    r = lcm(r, a[i]);
  }
  for (int i = 0; i < n; i++) {
    sum += r / a[i];
  }
  printf("%lf", (double)r / sum);
}
