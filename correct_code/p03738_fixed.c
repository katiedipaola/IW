#include <stdio.h>
int main(void) {
  double A, B;
  char *result;
  scanf("%lf%lf", &A, &B);
  if (A > B) {
    result = "GREATER";
  } else if (A < B) {
    result = "LESS";
  } else if (A == B) {
    result = "EQUAL";
  }
  printf("%s", result);
  return 0;
}