#include <stdio.h>

int main() {
  int array[100] = {0};
  int input;
  int max = 0;
  int i;
  while (scanf("%d", &input) != EOF) {
    array[input]++;
  }
  for (i = 0; i < 100; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  for (i = 0; i < 100; i++) {
    if (max == array[i]) {
      printf("%d\n", i);
    }
  }
  return 0;
}