#include <stdio.h>
#define MAX 100
int main(void) {
  int i, j, cnt = 0, minj, k, temp;
  int numbers[100];

  scanf("%d", &k);

  for (i = 0; i < k; i++) {
    scanf("%d", &numbers[i]);
  }

  for (i = 0; i < k; i++) {
    minj = i;
    for (j = i; j < k; j++) {
      if (numbers[j] < numbers[minj]) {
        minj = j;
      }
    }
    if (numbers[minj] < numbers[i]) {
      temp = numbers[i];
      numbers[i] = numbers[minj];
      numbers[minj] = temp;
      cnt++;
    }
  }

  for (i = 0; i < k; i++) {
    printf("%d", numbers[i]);
    if (i < k - 1) {
      printf(" ");
    }
  }

  printf("\n");
  printf("%d\n", cnt);

  return 0;
}
