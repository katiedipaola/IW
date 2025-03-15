#include <stdio.h>
int main(void) {
  char w[1000];
  scanf("%s", w);
  if (w[0] == 'S') {
    printf("Cloudy\n");
  }
  if (w[0] == 'C') {
    printf("Rainy\n");
  }
  if (w[0] == 'R') {
    printf("Sunny\n");
  }
  return 0;
}