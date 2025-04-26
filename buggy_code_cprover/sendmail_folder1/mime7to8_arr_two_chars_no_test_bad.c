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
    c2 = nondet_int ();
    if (c2 == EOF)
      break;

    
    fbuf[fb] = c1;
    fb++;

    
    fbuf[fb] = c2;
    fb++;
  }

  if (fb > 0)
  {
    
    fbuf[fb] = EOS;
  }

  return 0;
}
