#include "../stubs.h"

int main (void)
{
  char buffer[BASE_SZ+1];
  char input[BASE_SZ+70];
  char *buf;
  char *buflim;
  char *in;
  char cur;
  int anglelev;
  int skipping;

  in = input;
  buf = buffer;
  buflim = &buffer[sizeof buffer - 2];


  skipping = 0;

  cur = *in;
  while (cur != EOS)
  {
    if (buf >= buflim)
      skipping = 1;
    else
      skipping = 0;

    if (cur == '<')
    {
      if (!skipping)
        anglelev = 1;
    }
    else
      goto out;

    if (!skipping)
    {
      *buf = cur;
      buf++;
    }

out:
    in++;
    cur = *in;
  }

  if (anglelev > 0)
  {
    *buf = '>';
    buf++;
  }

  
  *buf = EOS;
  buf++;

  return 0;
}
