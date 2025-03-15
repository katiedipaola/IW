#include <stdio.h>

#define abs(v) ((v ^ (v >> 31)) - (v >> 31))

int main() {
  int x;
  int y;
  int a = 1;
  int yltx = 1;
  int xlty = 1;
  int zero = 0;

  scanf("%d%d", &x, &y);

  if (x > 0 && y > 0) {
    yltx = 0;
    xlty = 2;
  } else if (x < 0 && y < 0) {
    yltx = 2;
    xlty = 0;
  } else if (x == 0 && y > 0) {
    yltx = 0;
  } else if (y == 0 && x < 0) {
    xlty = 0;
  }

  if (abs(x) < abs(y)) {
    a = abs(y) - abs(x) + yltx;
  } else if (abs(x) > abs(y)) {
    a = abs(x) - abs(y) + xlty;
  } else if (x == y) {
    a = 0;
  }

  printf("%d\n", a);

  return 0;
}