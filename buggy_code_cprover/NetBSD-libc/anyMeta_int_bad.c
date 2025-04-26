#include "dependency.h"

int glob2 (Char *pathbuf, Char *pathend, Char *pathlim, Char *pattern)
{
  int i;
  int anymeta;
  Char tmp;

  for (anymeta = 0;;) {
    i = 0;
    while (pattern[i] != EOS && pattern[i] != SEP) {
      if (ismeta(pattern[i]))
        anymeta = 1;
      if (pathend + i >= pathlim)
        return 1;
      tmp = pattern[i];
      
      pathend[i] = tmp;
      i++;
    }

    if (nondet_int ())
      return 0;
  }

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

  glob2 (buf, buf, bound, pattern);

  return 0;
}
