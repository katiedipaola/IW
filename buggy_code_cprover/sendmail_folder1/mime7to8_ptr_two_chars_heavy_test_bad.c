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
    if (isascii(c1) && isspace(c1))
      continue;

    do
    {
      c2 = nondet_int ();
    } while (isascii(c2) && isspace(c2));
    if (c2 == EOF)
      break;

    if (c1 == '=' || c2 == '=')
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

    
    *fbufp = c2;

    
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
