#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  long long int i, j, k, l, ret;
  scanf("%lld %lld", &i, &j);
  if (j - i >= 2019)
    ret = 0;
  else {
    for (k = i; k < j; k++) {
      for (l = k + 1; l <= j; l++) {
        if (ret > (k * l) % 2019)
          ret = (k * l) % 2019;
      }
    }
  }
  printf("%lld\n", ret);
}
