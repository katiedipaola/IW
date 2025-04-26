#include "dependency.h"

uid_t geteuid(void)
{
  return nondet_short();
}

int seteuid(uid_t euid)
{
  if (nondet_int() == 0)
    return 0;
  return -1;
}

int     enable_signaling()
{
  return (0);
}

int     delay_signaling()
{
  return (0);
}

int readlink(const char *path, char *buf, int bufsiz)
{
  int n = nondet_int ();
  if (n < bufsiz && n >= 0)
    return n;
  return -1;
}

char *getcwd(char *buf, size_t size)
{
  if (nondet_int() == 0) {
    return NULL;
  }
  buf [size-1] = EOS;
  return buf;
}

