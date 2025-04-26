#include <stdio.h>
int main(void) {
  int d, t, s;
  scanf("%d %d %d", &d, &t, &s);
  if (s * t == d) {
    printf("Yes\n");
  } else if (s * t < d) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}