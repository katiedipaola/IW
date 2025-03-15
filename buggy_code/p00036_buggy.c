#include <stdio.h>

#define N 4

/** Application main entry point. */
int main(int argc, char *argv[]) {
  int res[N];
  int i;

  for (;;) {
    int *p = res;

    for (i = 0; i < 8 * 8; ++i) {
      int ch;

      do {
        ch = getchar();
        if (ch == EOF)
          goto ESCAPE;
      } while (ch != '0' && ch != '1');

      if (ch == '1') {
        *(p++) = i;
      }
    }
    for (i = 1; i < N; ++i) {
      res[i] -= *res;
    }

    if (res[1] == 1 && res[2] == 8 && res[3] == 9) {
      puts("A");
    } else if (res[1] == 8 && res[2] == 16 && res[3] == 4) {
      puts("B");
    } else if (res[1] == 1 && res[2] == 2 && res[3] == 3) {
      puts("C");
    } else if (res[1] == 7 && res[2] == 8 && res[3] == 15) {
      puts("D");
    } else if (res[1] == 1 && res[2] == 9 && res[3] == 10) {
      puts("E");
    } else if (res[1] == 8 && res[2] == 9 && res[3] == 17) {
      puts("F");
    } else if (res[1] == 1 && res[2] == 7 && res[3] == 8) {
      puts("G");
    }
  }
ESCAPE:

  return (0);
}