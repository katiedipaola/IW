#include <stdio.h>

int stack(int);

int main(int argc, char const *argv[]) {
  int input, data;

  while (1) {
    if (scanf("%d", &input) == EOF) {
      break;
    }

    data = stack(input);

    if (data != 0) {
      printf("%d\n", data);
    }
  }

  return 0;
}

int stack(int x) {
  static int box[100];
  static int num = 0;

  if (x == 0) {
    num--;
  } else {
    box[num] = x;
    num++;
    return 0;
  }

  return box[num];
}