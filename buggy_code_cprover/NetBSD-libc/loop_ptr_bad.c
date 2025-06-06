#include "dependency.h"

static int
glob3(Char *pathbuf, Char *pathend, Char *pathlim, Char *pattern)
{
  Char *dc;
  dc = pathend;
  for (;;)
    if (dc > pathlim) break;
    else {
      *dc = 1;
      dc++;
      
      if (*dc == EOS) break;
    }

  return 0;
}

int main ()
{
  Char *buf;
  Char *pattern;
  Char *bound;

  Char A [MAXPATHLEN+1];
  Char B [PATTERNLEN];

  buf = A;
  pattern = B;

  bound = A + sizeof(A) - 1;

  glob3 (buf, buf, bound, pattern);

  return 0;
}
