#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int k = 1;
  while (n > k * (k - 1) / 2) {
    k++;
  }
  if (n < k * (k - 1) / 2) {
    printf("No\n");
  } else {
    printf("Yes\n");
    int i;
    for (i = 0; i < k; i++) {
      printf("%d", k - 1);
      int j;
      for (j = 0; j < k - 1; j++) {
        if (i > j) {
          printf(" %d", n - (k - j) * (k - j - 1) / 2 + i - j);
        } else {
          printf(" %d", (n + 1) - (k - i) * (k - i - 1) / 2 + j - i);
        }
      }
      printf("\n");
    }
  }
  return 0;
}
