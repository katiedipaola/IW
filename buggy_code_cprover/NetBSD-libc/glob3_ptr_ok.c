#include "dependency.h"

struct dirent {
  char    d_name[MAXNAMLEN + 1];
};

static int
g_Ctoc(Char *str, char *buf, size_t len)
{
	char *dc;

	if (len == 0)
		return 1;

	for (dc = buf; len && (*dc++ = *str++) != EOS; len--)
		continue;

	return len == 0;
}

static int
glob3(Char *pathbuf, Char *pathend, Char *pathlim, Char *pattern)
{
  struct dirent dp;
  int error;
  char buf[MAXPATHLEN];


  *pathend = EOS;
	    
  if (nondet_int()) {
    if (nondet_int()) {
      if (g_Ctoc(pathbuf, buf, sizeof(buf)))
        return (GLOB_ABORTED);
      if (nondet_int())
        return (GLOB_ABORTED);
    }
    
    if (nondet_int())
      return (GLOB_ABORTED);
    
    return(0);
  }
  
  error = 0;
  while (nondet_int()) {
    char *sc;
    Char *dc;
    if (dp.d_name[0] == DOT && *pattern != DOT)
      continue;
    for (sc = dp.d_name, dc = pathend;;)
      if (dc > pathlim) break;
      else {
        *dc = *sc;
        dc++;
        sc++;
        
        if (*dc == EOS) break;
      }
    if (dc > pathlim && *pathlim != EOS) {
      if (nondet_int()) {
        error = GLOB_ABORTED;
        break;
      }
      else {
        
        *pathend = EOS;
        continue;
      }
    }

    if (nondet_int()) {
      
      *pathend = EOS;
      continue;
    }
  }

  return error;
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

  bound = A + sizeof(A)/sizeof(*A) - 1;

  glob3 (buf, buf, bound, pattern);

  return 0;
}
