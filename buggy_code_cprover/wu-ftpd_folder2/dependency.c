#include "dependency.h"

extern char nondet_char();

int readlink(const char *path, char *buf, int bufsiz)
{
  int n = nondet_int ();
  if (n < bufsiz && n >= 0)
    return n;
  return -1;
}

char *getcwd(char *buf, size_t size)
{
  int i;
  if (nondet_int() == 0) {
    return NULL;
  }
  for (i = 0; i < size-1; i++)
    buf[i] = nondet_char();
  buf [size-1] = EOS;
  return buf;
}
