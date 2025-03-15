#include <stdio.h>
#include <stdlib.h>

#define LINE_BUF_SIZE 1024

int main(void) {
  static char line[LINE_BUF_SIZE];

  while (fgets(line, sizeof(line), stdin) != NULL) {
    int x, a, b;
    if (sscanf(line, "%d %d %d", &x, &a, &b) != 3) {
      fputs("sscanf: Convert error\n", stderr);
      return EXIT_FAILURE;
    }

    int c = b - a;
    if (c <= 0) {
      printf("delicious\n");
    } else if (c <= x) {
      printf("safe\n");
    } else {
      printf("dangerous\n");
    }
  }

  return 0;
}