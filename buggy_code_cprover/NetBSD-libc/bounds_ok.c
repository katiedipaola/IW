#include "dependency.h"

int main ()
{
  Char pathbuf[MAXPATHLEN+1];

  Char *bound = pathbuf + sizeof(pathbuf)/sizeof(*pathbuf) - 1;

  *bound = 10;
  return 0;
}
