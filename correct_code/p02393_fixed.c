#include <stdio.h>

void swap(int *x, int *y) {

  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(int argc, const char *argv[]) {

  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  if (c < b) {
    swap(&c, &b);
  }

  if (b < a) {
    swap(&b, &a);
  }

  if (c < b) {
    swap(&c, &b);
  }

  printf("%d %d %d\n", a, b, c);
  return 0;
}