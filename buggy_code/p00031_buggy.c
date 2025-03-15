#include <stdio.h>

int main() {
  int i, j, x;
  int a = 1;
  int counter = 0;
  int array[9] = {0};
  while (scanf("%d", &x) != EOF) {
    for (i = 9; i >= 0; i--) {
      a = 1;
      for (j = 0; j < i; j++) {
        a = a * 2;
      }
      if (x >= a) {
        x = x - a;
        counter++;
        array[counter] = a;
      }
    }
    for (i = counter; i >= 1; i--) {
      if (i != 1) {
        printf("%d ", array[i]);
      } else {
        printf("%d\n", array[i]);
      }
    }
  }
  return 0;
}