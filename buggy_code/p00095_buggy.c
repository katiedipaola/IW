#include <stdio.h>

int main(void) {
  int n;
  int i;
  int a;
  int v;
  int a_max = 0;
  int v_max = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &v);
    if (v_max <= v) {
      v_max = v;
      a_max = a;
    } else if (v_max == v && a_max > a) {
      a_max = a;
    }
  }

  printf("%d %d\n", a_max, v_max);

  return (0);
}