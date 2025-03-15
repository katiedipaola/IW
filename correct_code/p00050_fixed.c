#include <stdio.h>
int main(void) {
  int i, j, n, m;
  char a[1000];
  gets(a);
  for (i = 0; i < 1000; i++) {
    int f = 0;
    if (a[i] == 'p')
      if (a[i + 1] == 'e')
        if (a[i + 2] == 'a')
          if (a[i + 3] == 'c')
            if (a[i + 4] == 'h')
              f = 1;

    if (f == 1) {
      a[i] = 'a';
      a[i + 1] = 'p';
      a[i + 2] = 'p';
      a[i + 3] = 'l';
      a[i + 4] = 'e';
      i += 4;
      continue;
    }
    if (a[i] == 'a')
      if (a[i + 1] == 'p')
        if (a[i + 2] == 'p')
          if (a[i + 3] == 'l')
            if (a[i + 4] == 'e')
              f = 1;
    if (f == 1) {
      a[i] = 'p';
      a[i + 1] = 'e';
      a[i + 2] = 'a';
      a[i + 3] = 'c';
      a[i + 4] = 'h';
      i += 4;
    }
  }
  printf("%s\n", a);

  return 0;
}