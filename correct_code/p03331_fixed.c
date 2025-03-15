#include <stdio.h>

int devide(int x) {
  int sum;
  if (x >= 10000) {
    sum = x / 10000;
    x = x - sum * 10000;
    sum += x / 1000;
    x = x - (x / 1000) * 1000;
    sum += x / 100;
    x = x - (x / 100) * 100;
    sum += x / 10;
    x = x - (x / 10) * 10;
    sum += x;
  } else if (x >= 1000) {
    sum = x / 1000;
    x = x - (x / 1000) * 1000;
    sum += x / 100;
    x = x - (x / 100) * 100;
    sum += x / 10;
    x = x - (x / 10) * 10;
    sum += x;
  } else if (x >= 100) {
    sum = x / 100;
    x = x - (x / 100) * 100;
    sum += x / 10;
    x = x - (x / 10) * 10;
    sum += x;
  } else if (x >= 10) {
    sum = x / 10;
    x = x - (x / 10) * 10;
    sum += x;
  } else {
    sum = x;
  }

  return sum;
}

int main(void) {
  int N;
  scanf("%d", &N);
  int a, min = 100;
  for (a = 1; a <= N / 2; a++) {
    int b = N - a;
    int suma = devide(a);
    int sumb = devide(b);
    if (sumb + suma < min) {
      min = sumb + suma;
    }
  }
  printf("%d\n", min);
  return 0;
}