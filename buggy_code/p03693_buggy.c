#include <stdio.h>
int main() {
  int r, g, b, in;
  scanf("%d%d%d", &r, &g, &b);
  in = r * 100 + g * 10 + b;
  if (in % 4 == 0)
    printf("Yes");
  else
    printf("No");
  return 0;
}