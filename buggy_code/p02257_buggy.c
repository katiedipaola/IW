#include <math.h>
#include <stdio.h>

int Prime(int);
int main() {
  int i, N, num, count = 0;

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &num);
    count += Prime(num);
  }
  printf("%d\n", count);

  return 0;
}

int Prime(int num) {
  int i;
  for (i = 2; i < sqrt(num); i++) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}