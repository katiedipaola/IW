#include <stdio.h>

int main() {
  int min, max, N, temp;
  min = 1000000000;
  max = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &temp);
    if (temp > max)
      max = temp;
    if (temp < min)
      min = min;
  }
  printf("%d", max - min);
  return 0;
}