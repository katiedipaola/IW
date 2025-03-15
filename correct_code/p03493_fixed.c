#include <stdio.h>

#define NUM 9999

int main(void) {
  char a[NUM];
  scanf("%s", a);

  int i, num;
  num = 0;

  for (i = 0; a[i] != '\n'; i++)
    if (a[i] == '1')
      num++;

  printf("%d", num);

  return 0;
}