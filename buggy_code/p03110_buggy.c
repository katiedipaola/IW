#include <stdio.h>

int main(void) {

  int n;
  int i, j;
  scanf("%d", &n);

  char m[n][5];
  double a[n];
  double tot = 0.0;

  for (i = 0; i < n; i++) {
    scanf("%lf", &a[i]);
    scanf("%s", m[i]);
  }

  for (j = 0; j < n; j++) {

    if (m[j] == "BTC")
      tot += a[j] * 380000.0;
    else
      tot += a[j];
  }

  printf("%f", tot);

  return 0;
}
