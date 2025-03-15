#include <stdio.h>

int main() {
  int a, b, c;
  int x;
  int i, j, k;
  int count = 0;

  scanf("%d", &a); // 500円の枚数
  scanf("%d", &b); // 100円の枚数
  scanf("%d", &c); // 50円の枚数
  scanf("%d", &x); // 合計金額

  for (i = 0; i <= a; i++) {
    for (j = 0; j <= b; j++) {
      for (k = 0; k <= c; k++) {
        int total = (500 * i) + (100 * j) + (50 * k);
        if (total == x) {
          count++;
        }
      }
    }
  }

  printf("%d\n", count);

  return 0;
}