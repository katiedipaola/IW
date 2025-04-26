#include <stdio.h>
int main(void) {
  int e1, e2, e3, e4;
  scanf("%d %d %d %d", &e1, &e2, &e3, &e4);
  if ((e1 == e2 && e3 == e4) || (e1 == e3 && e2 == e4) ||
      (e1 == e4 && e2 == e3))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
