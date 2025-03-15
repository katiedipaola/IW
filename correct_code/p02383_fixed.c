#include <stdio.h>
#include <string.h>

struct dice {
  int d[6], tmp[6];
};
struct dice dice1;

void init(int n[6]) {
  int i;
  for (i = 0; i < 6; i++) {
    dice1.d[i] = n[i];
  }
}
void rooldice(char c) {
  int i;
  for (i = 0; i < 6; i++) {
    dice1.tmp[i] = dice1.d[i];
  }
  if (c == 'N') {
    dice1.d[0] = dice1.tmp[1];
    dice1.d[1] = dice1.tmp[5];
    dice1.d[2] = dice1.tmp[2];
    dice1.d[3] = dice1.tmp[3];
    dice1.d[4] = dice1.tmp[0];
    dice1.d[5] = dice1.tmp[4];
  } else if (c == 'E') {
    dice1.d[0] = dice1.tmp[3];
    dice1.d[1] = dice1.tmp[1];
    dice1.d[2] = dice1.tmp[0];
    dice1.d[3] = dice1.tmp[5];
    dice1.d[4] = dice1.tmp[4];
    dice1.d[5] = dice1.tmp[2];
  } else if (c == 'W') {
    dice1.d[0] = dice1.tmp[2];
    dice1.d[1] = dice1.tmp[1];
    dice1.d[2] = dice1.tmp[5];
    dice1.d[3] = dice1.tmp[0];
    dice1.d[4] = dice1.tmp[4];
    dice1.d[5] = dice1.tmp[3];
  } else if (c == 'S') {
    dice1.d[0] = dice1.tmp[4];
    dice1.d[1] = dice1.tmp[0];
    dice1.d[2] = dice1.tmp[2];
    dice1.d[3] = dice1.tmp[3];
    dice1.d[4] = dice1.tmp[5];
    dice1.d[5] = dice1.tmp[1];
  } else if (c == 'R') {
    dice1.d[0] = dice1.tmp[0];
    dice1.d[1] = dice1.tmp[3];
    dice1.d[2] = dice1.tmp[1];
    dice1.d[3] = dice1.tmp[4];
    dice1.d[4] = dice1.tmp[2];
    dice1.d[5] = dice1.tmp[5];
  }
}

int main(void) {

  int n[6];
  int i;
  char ts;
  char t[110];

  for (i = 0; i < 6; i++) {
    scanf("%d", &n[i]);
  }
  init(n);
  scanf("%s", t);
  ts = strlen(t);
  for (i = 0; i < ts; i++) {
    rooldice(t[i]);
  }
  printf("%d\n", dice1.d[0]);
  return 0;
}