#include <stdio.h>
long a[200000];
int main(int argc, char const *argv[]) {
  long n, i;
  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  if (n % 2 == 0) {
    for (i = n - 1; i > 0; i -= 2) {
      printf("%ld ", a[2 * i - 1]);
    }
    printf("%ld", a[0]);
    for (i = 2; i < n; i += 2) {
      printf(" %ld", a[i]);
    }
  } else {
    for (i = n - 1; i > 0; i -= 2) {
      printf("%ld ", a[i]);
    }
    printf("%ld", a[0]);
    for (i = 1; i < n; i += 2) {
      printf(" %ld", a[i]);
    }
  }
  printf("\n");
  return 0;
}