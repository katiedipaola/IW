#include "../stubs.h"
#include "../base.h"

#define MAXLINE BASE_SZ

int main (void)
{
  char fbuf[MAXLINE+1];
  char *fbufp;
  int c1;

  fbufp = fbuf;

  while ((c1 = nondet_int ()) != EOF)
  {
    
    *fbufp++ = c1;
    if (fbufp >= &fbuf[MAXLINE])
      fbufp = fbuf;
  }

  if (fbufp > fbuf)
  {
    
    *fbufp = EOS;
  }

  return 0;
}
