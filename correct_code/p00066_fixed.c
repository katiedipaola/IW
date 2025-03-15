// AOJ Volume 0 Problem 0066

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char in_str[81];
  int field[9];
  int i, j;
  int check;

  while (scanf("%s", in_str) != EOF) {

    for (i = 0; i < 9; i++) {
      if (in_str[i] == 'o') {
        field[i] = 1;
      } else if (in_str[i] == 'x') {
        field[i] = -1;
      } else {
        field[i] = 0;
      }
    }

    for (i = 0; i < 3; i++) {
      check = 0;
      for (j = 0; j < 3; j++) {
        check += field[i * 3 + j];
      }
      if (abs(check) == 3) {
        goto end;
      }
      check = 0;
      for (j = 0; j < 3; j++) {
        check += field[i + j * 3];
      }
      if (abs(check) == 3) {
        goto end;
      }
    }

    check = field[0] + field[4] + field[8];
    if (abs(check) == 3) {
      goto end;
    }

    check = field[2] + field[4] + field[6];

  end:
    if (check == 3) {
      printf("o\n");
    } else if (check == -3) {
      printf("x\n");
    } else {
      printf("d\n");
    }
  }

  return (0);
}