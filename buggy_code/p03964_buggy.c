#include <stdio.h>
int main(void) {
  int n, i;
  long long t, a, anst = 1, ansa = 1, tt, ta;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld %lld", &t, &a);
    if (anst % t)
      tt = anst / t + 1;
    else
      tt = anst / t;
    if (ansa % a)
      ta = ansa / a + 1;
    else
      ta = ansa / a;
    if (t * tt > a * ta) {
      anst = t * tt;
      ansa = a * tt;
    } else {
      anst = t * ta;
      ansa = a * ta;
    }
  }
  printf("%lld\n", anst + ansa);
  return 0;
}