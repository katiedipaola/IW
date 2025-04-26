#include "dependency.h"

char *fb_realpath(const char *path, char *resolved)
{
  int rootd;
  char wbuf[MAXPATHLEN];
  int resultcode;
  char tmp [MAXPATHLEN];
  int p, q;

  (void) strncpy(resolved, path, MAXPATHLEN - 1);
  resolved[MAXPATHLEN - 1] = EOS;

  q = istrrchr(resolved, '/');
  if (q != -1) {
    p = q + 1;               
  }
  else
    p = 0;

  strcpy(wbuf, resolved + p);

  if (getcwd(resolved, MAXPATHLEN) == NULL)
    return NULL;

  if (resolved[0] == '/' && resolved[1] == EOS)
    rootd = 1;
  else
    rootd = 0;
 
  if (wbuf[0] != EOS) {
    if (strlen(resolved) + strlen(wbuf) + !rootd + 1 > MAXPATHLEN) {
      return NULL;                                
    }
    if (rootd == 0)
      (void) strcat(resolved, "/");

                                
    (void) r_strcat(resolved, wbuf);
  }
  return (NULL);
}

int main ()
{
  char pathname [MAXPATHLEN];
  char resolved [MAXPATHLEN];

  pathname [MAXPATHLEN-1] = EOS;
  resolved [MAXPATHLEN-1] = EOS;

  fb_realpath(pathname, resolved);

  return 0;
}
