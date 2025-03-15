#include <stdio.h>

int main(void) {
  int time[5], i, timest[5], mintime = 10, minum, sum = 0;
  for (i = 0; i < 5; i++) {
    scanf("%d", &time[i]);
    timest[i] = time[i] % 10;
    if (timest[i] < mintime && timest != 0) {
      minum = i;
      mintime = timest[i];
    }
  }
  for (i = 0; i < 5; i++) {
    if (i != minum && timest[i] != 0)
      time[i] = (time[i] / 10 + 1) * 10;
    sum += time[i];
  }
  printf("%d\n", sum);
  return 0;
}