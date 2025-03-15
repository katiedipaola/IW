#include <stdio.h>

int fib(int);
int f[45];

int main() {
  int a, n;

  scanf("%d", &n);

  a = fib(n);
  printf("%d\n", a);

  return 0;
}

int fib(int n) {

  int a;

  if (a = f[n])
    return a;

  if (n == 0 || n == 1) {
    a = 1;
  } else
    a = fib(n - 1) + fib(n - 2);

  f[n] = a;
  return a;
}
