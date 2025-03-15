#include <stdio.h>
#define MAX 301

int main() {
  char array[MAX] = {'\0'};
  int i, j;
  int count[4] = {0};
  int temp;

  scanf("%s", &array);

  for (i = 0; i < MAX; i++) {
    if (array[i] == 'K')
      count[0]++;
    if (array[i] == 'U')
      count[1]++;
    if (array[i] == 'P')
      count[2]++;
    if (array[i] == 'C')
      count[3]++;
  }

  for (i = 0; i < 4; i++) {
    for (j = 2; j >= i; j--) {
      if (count[j] < count[j + 1]) {
        temp = count[j];
        count[j] = count[j + 1];
        count[j + 1] = temp;
      }
    }
  }
  printf("%d\n", count[3]);

  return 0;
}