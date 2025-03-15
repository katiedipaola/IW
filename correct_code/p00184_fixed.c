#include <stdio.h>
int main(void) {
  int input, i, j, people;
  while (scanf(" %d", &people), people) {
    int age[7] = {0};
    for (i = 0; i < people; i++) {
      scanf(" %d", &input);
      for (j = 1; input - 10 * j >= 0 && j < 7; j++) {
      }
      age[j - 1]++;
      // printf("    %d\n", j-1);
    }
    for (i = 0; i < 7; i++) {
      printf("%d\n", age[i]);
    }
  }
  return 0;
}