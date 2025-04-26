#include "dependency.h"

char *
realpath(const char *pathname, char *result, char* chroot_path)
{
  char curpath[MAXPATHLEN],
    workpath[MAXPATHLEN],
    namebuf[MAXPATHLEN];

  if (result == NULL)
    return(NULL);

  if(pathname == NULL){
    *result = EOS; 
    return(NULL);
  }

  workpath[MAXPATHLEN-1] = EOS;
  strcpy(curpath, pathname);
  strcpy(namebuf, workpath);

  
  r_strncat(namebuf, curpath, MAXPATHLEN-strlen(namebuf)-1);

  return result;
}

int main ()
{
  char pathname [MAXPATHLEN];
  char result [MAXPATHLEN];
  char chroot_path [MAXPATHLEN];

  pathname [MAXPATHLEN-1] = EOS;
  result [MAXPATHLEN-1] = EOS;
  chroot_path [MAXPATHLEN-1] = EOS;

  realpath(pathname, result, chroot_path);

  return 0;
}
