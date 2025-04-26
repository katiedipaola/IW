#include <stdio.h>
int main(void) {

  int n, m, i, j, count[10001], carin, carout, in, out, box, zero;

  scanf("%d", &n);
  scanf("%d", &m);

  for (i = 1; i <= n; i++) {

    scanf("%d %d", &in, &out);

    if (i == 1) {
      count[i] = m + in - out;
    } else
      count[i] = count[i - 1] + in - out;

    if (count[i] < 0) {
      zero = 0;
    }

    if (i == 1 && m >= count[i])
      box = m;
    else if (i == 1)
      box = count[i];

    if (i > 1 && box <= count[i])
      box = count[i];
    else
      box = box;
  }

  if (zero == 0)
    printf("0\n");
  else if (box > 0)
    printf("%d\n", box);

  return 0;
}