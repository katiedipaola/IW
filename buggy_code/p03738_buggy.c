#include <stdio.h>
int main(void) {
  int A, B;
  char *result;
  scanf("%d%d", &A, &B);
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