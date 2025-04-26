#include <stdint.h>
#include <stdio.h>
int main(void) {
  int64_t n;
  int64_t tp[5];
  scanf("%ld", &n);
  for (int i = 0; i < 5; i++)
    scanf("%ld", &tp[i]);
  int64_t tpmin = tp[0];
  int tpindex = 0;
  for (int i = 0; i < 5; i++) {
    if (tp[i] < tpmin) {
      tpmin = tp[i];
      tpindex = i;
    }
  }
  int64_t mov = 0;
  mov += (n / tpmin) + (n % tpmin) - 1 + 5;
  printf("%ld\n", mov);
  return 0;
}