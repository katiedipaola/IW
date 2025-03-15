#include <stdio.h>

int main(int argc, char const *argv[]) {
  int quant;
  int sum = 0;
  scanf("%d\n", &quant);

  int score[quant];
  int is10n[quant];

  for (int i = 0; i < quant; i++) {
    (void)scanf("%d", &score[i]);
    if (score[i] % 10 == 0) { // true-> 0, false -> 1;
      is10n[i] = 0;
    } else {
      is10n[i] = 1;
    }
    sum += score[i];
  }

  if (sum % 10 != 0) {
    printf("%d\n", sum);
    return 0;
  }

  int min = 101;
  for (int i = 0; i < quant; i++) {
    if (score[i] * is10n[i] != 0 && min > score[i]) {
      min = score[i];
    }
  }

  if (min == 101) {
    printf("0\n");
  } else {
    printf("%d\n", sum - min);
  }
  return 0;
}
