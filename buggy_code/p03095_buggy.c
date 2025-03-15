#include <stdio.h>
int data[26] = {};
int mod = 1e9 + 7, i, n;
int main(void) {
  scanf("%d\n", &n);
  for (i = 0; i < n; ++i)
    data[(int)(getchar() - 'a')]++;
  long ans = 1;
  for (i = 0; i < n; ++i)
    ans = (ans * (data[i] + 1)) % mod;
  printf("%ld\n", ans - 1);
  return 0;
}