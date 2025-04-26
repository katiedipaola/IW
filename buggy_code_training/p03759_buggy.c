#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if ((b - a) == (c - b)) {
    printf("yes");
  } else {
    printf("no");
  }
}
