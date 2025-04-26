#include "dependency.h"

struct dirent {
  char    d_name[MAXNAMLEN + 1];
};

static int
g_Ctoc(Char *str, char *buf, size_t len)
{
  int i;

  if (len == 0)
    return 1;

  for (i = 0; len && (buf[i] = str[i]) != EOS; len--)
    i++;

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
    int i;
    if (dp.d_name[0] == DOT && *pattern != DOT)
      continue;
    i = 0;
    for (;;)
      if (pathend + i > pathlim) break;
      else {
        pathend[i] = dp.d_name[i];
        i++;
        
        if (pathend[i] == EOS) break;
      }
    if (pathend + i > pathlim && *pathlim != EOS) {
      if (nondet_int()) {
        error = GLOB_ABORTED;
        break;
      }
      else {
        
        pathend[i] = EOS;
        continue;
      }
    }
    if (nondet_int()) {
      
      pathend[i] = EOS;
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
