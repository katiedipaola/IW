#include <stdio.h>
int c(char *p, int d) { return ((26 + *p - *(p + 1)) % 26 == d); }
int a(char *p) { return ((*p < 'a') || (*p > 'z')); }

char *decode(char *inbuf, int s) {
  int p = 0;
  while (inbuf[p]) {
    if (!a(&inbuf[p])) {
      int t = inbuf[p] + s;

      if (t > 'z')
        inbuf[p] = (char)(t - 26);
      else if (t < 'a')
        inbuf[p] = (char)(t + 26);
      else
        inbuf[p] = (char)t;
    }
    p++;
  }
  return (inbuf);
}

int main(s) {
  char inbuf[82];
  while (fgets(inbuf, 80, stdin)) {
    char *p = inbuf;
    while (*p) {
      s = 0;
      if ((c(p, 12)) && ((c(p + 1, 3) && a(p + 3)) ||
                         (c(p + 1, 7) && c(p + 2, 7) && a(p + 4)) ||
                         (c(p + 1, 25) && c(p + 2, 16) && a(p + 4)))) {
        s = 't' - *p;
        p += 3;
      }
      if (s)
        break;
      p++;
    }
    printf("%s", decode(inbuf, s));
  }
  return 0;
}