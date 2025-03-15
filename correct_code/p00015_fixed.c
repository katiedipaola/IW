#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int makeBigInt(char *, const char *);
int sumBigInt(char *, const char *, const char *);

int main(void) {
  int i, n, err;
  char buf[1024], a[81], b[81];

  scanf("%d", &n);

  while (n--) {
    err = 0;

    scanf(" %s", buf);

    err += makeBigInt(a, buf);

    scanf(" %s", buf);

    err += makeBigInt(b, buf);

    err += sumBigInt(buf, a, b);

    if (err < 0) {
      printf("overflow\n");
      continue;
    }

    if (sumBigInt(buf, a, b))
      printf("overflow\n");
    else {
      for (i = 0; i < 79; i++)
        if (buf[i] != '0')
          break;

      printf("%s\n", buf + i);
    }
  }
}

int makeBigInt(char *s, const char *t) {
  int l, i;

  l = 80 - strlen(t);

  if (l < 0)
    return -1;

  for (i = 0; i < l; i++)
    s[i] = '0';

  strcpy(s + l, t);

  return 0;
}

int sumBigInt(char *sum, const char *a, const char *b) {
  int i, n;
  int m = 0;

  for (i = 79; i >= 0; i--) {
    n = (a[i] - '0') + (b[i] - '0') + m;
    m = n / 10;
    sum[i] = (n % 10) + '0';
  }

  sum[80] = '\0';

  return (m ? -1 : 0);
}