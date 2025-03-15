#include <stdio.h>
int main() {
  int e, x, y, z, r;
  for (; scanf("%d", &e), e;) {
    r = 10000000;
    for (z = 0; z * z * z <= e; z++)
      for (y = 0; y * y <= e - z * z * z; y++)
        if (e - y * y - z * z * z + y + z < r)
          r = e - y * y - z * z * z + y + z;
    printf("%d\n", r);
  }
  return 0;
}