#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  int atai[3];
  for (i = 0; i < 3; i++) {
    char num[5];
    scanf("%s", &num);
    atai[i] = atoi(num);
  }
  int ans;
  ans = (atai[0] + atai[1]) * atai[2] / 2;
  printf("%d\n", ans);
}