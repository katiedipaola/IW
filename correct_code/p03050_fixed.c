#include <stdio.h>
typedef long long int lli;

#define min(a, b) (a < b ? a : b)

int main(void) {
  lli n;
  scanf("%ld", &n);

  //  printf("%ld\n",n);
  lli ans = 0, sq, i;
  i = 1;
  sq = 2;
  while (sq < n) {
    if (n % i == 0) {
      ans += n / i - 1;
      //      printf("i=%4ld, %ld\n",i,ans);
    }
    i++;
    sq = i * (i + 1);
  }
  printf("%ld", ans);

  return 0;
}
