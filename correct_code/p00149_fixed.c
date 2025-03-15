#include <stdio.h>

int eyejudge(double eyesight);

int main(void) {
  int right[4] = {0};
  int left[4] = {0};
  double rsig, lsig;
  int i, j;

  while (scanf("%lf %lf", &lsig, &rsig) != EOF) {
    if (eyejudge(lsig) == 0 || eyejudge(rsig) == 0)
      return (0);
    left[eyejudge(lsig) - 1]++;
    right[eyejudge(rsig) - 1]++;
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 1; j++) {
      printf("%d %d", left[i], right[i]);
    }
    putchar('\n');
  }

  return (0);
}

int eyejudge(double eyesight) {
  if (eyesight >= 1.1)
    return (1);
  else if (eyesight >= 0.6 && eyesight < 1.1)
    return (2);
  else if (eyesight >= 0.2 && eyesight < 0.6)
    return (3);
  else if (eyesight < 0.2)
    return (4);
  else
    return (0);
}