#include <stdio.h>

int main() {
  int num;
  int dig;
  int sum = 0;

  scanf("%d", &num);

  while (num) {
    dig = num % 10;
    sum = sum + dig;
    num = num / 10;
  }
  if (num % sum == 0)
    printf("Yes");
  else
    printf("No");

  return 0;
}
