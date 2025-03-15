#include <math.h>
#include <stdio.h>
int main() {
  int data[5], sum = 0, i, ave;
  for (i = 0; i < 5; i++) {
    scanf("%d", &data[i]);
    if (data[i] < 40) {
      data[i] = 40;
    }
    sum = sum + data[i];
  }
  ave = sum / 5;
  printf("%d\n", ave);
  return 0;
}