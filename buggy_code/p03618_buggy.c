#include <stdio.h>
#include <string.h>

typedef long long lli;

#define CHARMAX 256
char a[200001];
int freq[CHARMAX];

int main() {
  int i, n = 0;
  for (i = 0; i < CHARMAX; ++i) {
    freq[i] = 0;
  }
  scanf("%s", a);
  for (n = 0; a[n] != '\0'; ++n) {
    freq[(int)(a[n])]++;
  }
  lli res = (lli)(n - 1) * n / 2ll;
  for (i = 0; i < CHARMAX; ++i) {
    int f = freq[i];
    if (f > 0) {
      res -= (lli)(f - 1) * f / 2ll;
    }
  }
  printf("%lld\n", res);
  return 0;
}
