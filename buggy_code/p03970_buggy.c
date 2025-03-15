#include <stdio.h>
int main() {
  char w[20], s[] = {"C0DEFESTIVAL2O16"};
  int i, j = 0;
  scanf("%s", w);
  for (i = 0; s[i]; i++) {
    if (s[i] - w[i])
      j++;
  }
  printf("%d\n", j);
  return 0;
}
