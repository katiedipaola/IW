#include <stdio.h>

int swap(int *a, int *b) {
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;

  return (0);
}

int main(void) {
  int n;
  int i, j;
  int sides[3];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", sides + j);
    }
    if (sides[0] < sides[1])
      swap(sides, sides + 1);
    if (sides[0] < sides[2])
      swap(sides, sides + 2);
    puts(sides[0] == sides[1] * sides[1] + sides[2] * sides[2] ? "YES" : "NO");
  }

  return (0);
}