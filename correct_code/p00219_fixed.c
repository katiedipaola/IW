#include <stdio.h>
int main(void) {
  int i, j, n, data[10000 + 1], suu[10000 + 1];
  scanf("%d", &n);
  while (n != 0) {
    for (i = 0; i < 10; i++) {
      suu[i] = 0;
    }
    for (j = 0; j < n; j++) {
      scanf("%d", &data[j]);
    }
    for (i = 0; i < 10; i++) {
      for (j = 0; j < n; j++) {
        if (data[j] == i) {
          suu[i]++;
        }
      }
    }
    for (i = 0; i < 10; i++) {
      if (suu[i] != 0) {
        for (j = 0; j < suu[i]; j++) {
          printf("*");
        }
        printf("\n");
      } else if (suu[i] == 0) {
        printf("-\n");
      }
    }
    scanf("%d", &n);
  }
  return 0;
}