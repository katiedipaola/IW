#include <stdio.h>
int main(void) {
  int N;
  scanf("%d", &N);
  if (N % 10 == 0) {
    printf("hon");
  } else if ((N - 1) % 5 == 0) {
    printf("pon");
  } else if ((N - 2) % 5 == 0) {
    printf("hon");
  } else if ((N - 3) % 5 == 0 && N % 2 == 0) {
    printf("pon");
  } else if ((N - 4) % 5 == 0) {
    printf("hon");
  } else if (N % 5 == 0) {
    printf("hon");
  } else {
    printf("bon");
  }
  return 0;
}