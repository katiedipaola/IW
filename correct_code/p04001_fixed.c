#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i, j, k, l, len;
  long long T;
  char S[15], temp[20], num[15];
  scanf("%s", &S);
  T = 0;
  len = strlen(S);
  for (i = 0; i < len; i++) {
    temp[2 * i] = S[i];
    temp[2 * i + 1] = 0;
  }
  for (j = 0; j < (1 << (len - 1)); j++) {
    k = j;
    l = 0;
    for (i = 0; i < len; i++)
      temp[2 * i + 1] = 0;
    while (k) {
      if (k & 1)
        temp[2 * l + 1] = '+';
      l++;
      k >>= 1;
    }
    l = 0;
    for (i = 0; i < 2 * len; i++) {
      if (temp[i] == '+') {
        memmove(num, S + (l / 2), (i + 1 - l) / 2);
        T += atoll(num);
        l = i + 1;
        memset(num, 0, 10);
      }
    }
    memmove(num, S + (l / 2), (i + 1 - l) / 2);
    T += atoll(num);
    memset(num, 0, 15);
  }
  printf("%lld\n", T);

  return 0;
}
