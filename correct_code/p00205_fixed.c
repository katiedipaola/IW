#include <stdio.h>
typedef struct {
  int g, t, p;
} gtp;
int main(void) {
  int n, i, j;
  int A[10];
  char str[10];
  gtp cnt;

  while (1) {
    cnt.g = 0;
    cnt.t = 0;
    cnt.p = 0;
    for (i = 0; i < 5; i++) {
      fgets(str, sizeof(str), stdin);
      sscanf(str, "%d", &n);
      switch (n) {
      case 0:
        return 0;
      case 1:
        cnt.g += 1;
        break;
      case 2:
        cnt.t += 1;
        break;
      case 3:
        cnt.p += 1;
        break;
      }
      A[i] = n;
    }
    if ((cnt.g != 0 && cnt.t != 0 && cnt.p != 0) ||
        (cnt.g == 0 && cnt.t == 0) || (cnt.t == 0 && cnt.p == 0) ||
        (cnt.p == 0 && cnt.g == 0)) {
      for (j = 0; j < 5; j++)
        A[j] = 3;
    } else if (cnt.g == 0) {
      for (j = 0; j < 5; j++) {
        switch (A[j]) {
        case 2:
          A[j] = 1;
          break;
        case 3:
          A[j] = 2;
          break;
        }
      }
    } else if (cnt.t == 0) {
      for (j = 0; j < 5; j++) {
        switch (A[j]) {
        case 3:
          A[j] = 1;
          break;
        case 1:
          A[j] = 2;
          break;
        }
      }
    } else if (cnt.p == 0) {
      for (j = 0; j < 5; j++) {
        switch (A[j]) {
        case 1:
          A[j] = 1;
          break;
        case 2:
          A[j] = 2;
          break;
        }
      }
    }
    for (j = 0; j < 5; j++)
      printf("%d\n", A[j]);
  }
  return 0;
}