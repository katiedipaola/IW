#include "../stubs.h"
#include "../base.h"

#define MAXLINE BASE_SZ

int main (void)
{
  char fbuf[MAXLINE+1];
  char *fbufp;
  int c1, c2;

  fbufp = fbuf;

  while ((c1 = nondet_int ()) != EOF)
  {
    c2 = nondet_int ();
    if (c2 == EOF)
      break;

    if (c1 == '=' || c2 == '=')
      continue;

    
    *fbufp = c1;

    
    if (*fbufp++ == '\n' || fbufp >= &fbuf[MAXLINE])
    {
      if (fbufp <= fbuf)
	fbufp = fbuf;
      else if (*--fbufp != '\r') 
	fbufp++;

      
      *fbufp = EOS;
      fbufp = fbuf;
    }

    
    *fbufp = c2;

    
    if (*fbufp++ == '\n' || fbufp >= &fbuf[MAXLINE])
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
