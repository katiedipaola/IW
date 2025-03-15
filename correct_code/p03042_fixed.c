#include <stdio.h>

int main() {
  int number, number_upper, number_bottom, flag = 0;
  scanf("%d", &number);
  number_bottom = number % 100;
  number_upper = (number - number_bottom) / 100;
  if ((1 <= number_bottom && number_bottom <= 12) &&
      !(1 <= number_upper && number_upper <= 12)) {
    printf("YYMM\n");
  } else if ((1 <= number_upper && number_upper <= 12) &&
             !(1 <= number_bottom && number_bottom <= 12)) {
    printf("MMYY\n");
  } else if ((1 <= number_upper && number_upper <= 12) &&
             (1 <= number_bottom && number_bottom <= 12)) {
    printf("AMBIGUOUS\n");
  } else {
    printf("NA\n");
  }
  return 0;
}
