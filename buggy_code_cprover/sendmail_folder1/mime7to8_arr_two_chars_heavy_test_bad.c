#include "../stubs.h"
#include "../base.h"

#define MAXLINE BASE_SZ

int main (void)
{
  char fbuf[MAXLINE+1];
  int fb;
  int c1, c2;

  fb = 0;
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

    
    fbuf[fb] = c1;

    
    if (fbuf[fb] == '\n')
    {
      fb--;
      if (fb < 0)
	fb = 0;
      else if (fbuf[fb] != '\r') 
	fb++;

      
      fbuf[fb] = 0;
      fb = 0;
    }
    else
      fb++;

    
    fbuf[fb] = c2;

    
    if (fbuf[fb] == '\n')
    {
      fb--;
      if (fb < 0)
	fb = 0;
      else if (fbuf[fb] != '\r') 
	fb++;

      
      fbuf[fb] = 0;
      fb = 0;
    }
    else
      fb++;
  }

  if (fb > 0)
  {
    
    fbuf[fb] = EOS;
  }

  return 0;
}
