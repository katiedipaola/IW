#include "../stubs.h"

int main (void)
{

  char outfile[BASE_SZ];

  char *outp = outfile;

  int c1, c2;

  int nchar = 0;

  while ((c1 = nondet_char ()) != EOS)
  {
    if (c1 == '=')
    {
      if ((c1 = nondet_char ()) == EOS)
	break; 
      if (c1 == '\n')
      {
	outp = outfile;
	nchar = 0;
	continue;
      }
      else
      {

	if ((c2 = nondet_char ()) == EOS)
	  break;

	nchar++;
	if (nchar > BASE_SZ)
	  break;

	
	*outp++ = c1;
      }
    }
    else
    {
      nchar++;
      if (nchar > BASE_SZ)
	break;

      
      *outp++ = c1;

      if (c1 == '\n')
	break;
    }
  }

  
  *outp++ = EOS;
  return 0;
}
