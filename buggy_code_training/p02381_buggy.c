#include <math.h>
#include <stdio.h>
int main(void) {
  int num, score[1000], sum, i;
  double average, sigma;
  while (1) {
    scanf("%d", &num);
    if (num == 0)
      break;
    sum = 0;
    for (i = 0; i < num; i++) {
      scanf("%d", &score[i]);
      sum += score[i];
    }
    average = 1.0 * sum / num;
    sum = 0;
    for (i = 0; i < num; i++)
      sum += (score[i] - average) * (score[i] - average);
    sigma = sum / num;
    printf("%.8lf\n", sqrt(sigma));
  }
  return 0;
}