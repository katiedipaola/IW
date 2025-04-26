#include <stdio.h>

/*ûj BMI©çQQðø¢½lÅär·é*/

int main() {
  int i, h, w, n, j, no = 100000000;
  double BMI, BMI2 = 1000, BMIH;

  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break; /*whileI¹ð*/

    for (j = 0; j < n; j++) {
      scanf("%d%d%d", &i, &h, &w);
      BMI = (double)w / ((h / 100.0) * (h / 100.0));
      BMIH = (BMI - 22);

      if (BMIH < 0) {
        BMIH = -BMIH;
      }

      if (BMIH < BMI2) {
        BMI2 = BMIH;
        no = i;
      } else if (BMIH == BMI && i < no) {
        no = i;
      }

    } /*E for*/

    printf("%d\n", no);
    no = 100000000;
  } /*E while*/

  return 0;
} /*E main*/