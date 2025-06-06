#include "dependency.h"

char *
realpath(const char *pathname, char *result, char* chroot_path)
{
  char curpath[MAXPATHLEN],
    workpath[MAXPATHLEN],
    linkpath[MAXPATHLEN],
    namebuf[MAXPATHLEN];
  int len;
  int where;
  int ptr;
  int last;

  if (result == NULL)
    return(NULL);

  if(pathname == NULL){
    *result = EOS; 
    return(NULL);
  }

  strcpy(curpath, pathname);

  if (*pathname != '/') {
    uid_t userid;
		
    if (!getcwd(workpath,MAXPATHLEN)) {
      userid = geteuid();
      delay_signaling();
      seteuid(0);
      if (!getcwd(workpath,MAXPATHLEN)) {
        strcpy(result, ".");
        seteuid(userid);
        enable_signaling();
        return (NULL);
      }
      seteuid(userid);
      enable_signaling();
    }
  } else
    *workpath = EOS;

  where = 0;
  while (curpath[where] != EOS) {
    if (!strcmp(curpath + where, ".")) {
      where++;
      continue;
    }
    if (!strncmp(curpath + where, "./", 2)) {
      where += 2;
      continue;
    }
    if (!strncmp(curpath + where, "../", 3)) {
      where += 3;
      ptr = last = 0;
      while (workpath[ptr] != EOS) {
        if (workpath[ptr] == '/')
          last = ptr;
        ptr++;
      }
      workpath[last] = EOS;
      continue;
    }
    ptr = istrchr(curpath + where, '/');
    if (curpath[ptr] == EOS)
      ptr = where + strlen(curpath + where) - 1;
    else
      curpath[ptr] = EOS;

    strcpy(namebuf, workpath);
    for (last = 0; namebuf[last] != EOS; last++)
      continue;

  }

  if (nondet_int() == 1) {
    len = readlink(namebuf, linkpath, MAXPATHLEN);
    if (len <= 0)
      return NULL;
  
    linkpath[len] = EOS;

    if (linkpath[0] == '/')
      workpath[0] = EOS;
    if (where[0] != EOS) {
      
      r_strncat(linkpath, "/", MAXPATHLEN-strlen(linkpath)-1);
      if (strlen(linkpath)+strlen(where)>=MAXPATHLEN) {
	return NULL;
      }
      
      r_strncat(linkpath, where, MAXPATHLEN-strlen(linkpath)- 1);
    }
    if (strlen(linkpath) >= MAXPATHLEN) {
      return NULL;
    }
    
    r_strcpy(curpath, linkpath);
  }

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
