#include "../stubs.h"

int main (void)
{

  char outfile[BASE_SZ];


  int c1, c2;

  int nchar = 0;

  int out = 0;

  while ((c1 = nondet_char ()) != EOS)
  {
    if (c1 == '=')
    {
      if ((c1 = nondet_char ()) == EOS)
	break; 
      if (c1 == '\n')
      {
	out = 0;
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

	
	outfile[out] = c1;
	out++;
      }
    }
    else
    {
      nchar++;
      if (nchar > BASE_SZ)
	break;

      
      outfile[out] = c1;
      out++;

      if (c1 == '\n')
	break;
    }
  }

  
  outfile[out] = EOS;
  out++;
  return 0;
}
