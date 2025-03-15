#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  int b = 0;
  int t = n;
  while (n) {
    b += n % 10;
    n /= 10;
  }
  if (t % b == 0)
    printf("Yes");
  else
    printf("No");
  return 0;
}