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
    if (c1 == '=')
      continue;

    
    *fbufp = c1;

    
    if (*fbufp++ == '\n')
    {
      if (fbufp <= fbuf)
	fbufp = fbuf;
      else if (*--fbufp != '\r') 
	fbufp++;

      
      *fbufp = EOS;
      fbufp = fbuf;
    }
  }

  if (fbufp > fbuf)
  {
    
    *fbufp = EOS;
  }

  return 0;
}
