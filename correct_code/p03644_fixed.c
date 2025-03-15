#include <stdio.h>

int count_div(int x) {
  int count = 1;
  while ((x % 2) != 1) {
    x /= 2;
    count++;
  }
  return count;
}

int main() {
  int num, i;
  int divmax = 0, counter = 0;
  int ans;

  scanf("%d", &num);

  for (i = num; i > num / 2; i--) {
    counter = count_div(i);
    if (divmax < counter) {
      divmax = counter;
      ans = i;
    }
  }
  printf("%d\n", ans);

  return 0;
}