#include <stdio.h>
int main() {
  int n, a, b, c, d[100], y, i, p, j, tmp, max, k;
  int price, calorie, cur;
  scanf("%d %d %d %d", &n, &a, &b, &c);

  for (i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      if (d[j] < d[i]) {
        tmp = d[j];
        d[j] = d[i];
        d[j] = tmp;
      }
    }
  }

  price = a, calorie = c;
  max = calorie / price;
  for (i = 1; i < n; i++) {
    price += b;
    calorie += d[i];
    cur = calorie / price;
    if (max > cur) {
      break;
    }
    max = cur;
  }
  printf("%d\n", max);
  return 0;
}